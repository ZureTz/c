#include <bits/stdc++.h>

typedef long long i64;
inline i64 rd() {
  i64 k = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9')
    f = (c == '-') ? 0 : f, c = getchar();
  while (c >= '0' && c <= '9')
    k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();
  return f ? k : -k;
}
inline void wr(i64 x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    wr(x / 10);
  putchar((x % 10) ^ '0');
}

const int N = 100010, LOG_N = 18;
const i64 INF = 1145141919810114514ll;

i64 d[N];
int f[N], sz[N];
namespace list
{
    int n;
    int pre[N * 3], nxt[N * 3], val[N * 3], cnt;
    int head[N], tail[N], val_idx[N];
    int new_node() { return ++cnt; }
    void init(int _n)
    {
        n = _n;
        for (int i = 1; i <= n; ++i)
        {
            head[i] = new_node(), tail[i] = new_node();
            pre[tail[i]] = head[i], nxt[head[i]] = tail[i];
        }
    }
    void insert(int pos, int v) // insert v at pos's nxt
    {
        int x = new_node();
        val_idx[v] = x, val[x] = v;
        pre[x] = pos, nxt[x] = nxt[pos], pre[nxt[pos]] = x, nxt[pos] = x;
    }
    void remove(int pos)
    {
        pre[nxt[pos]] = pre[pos], nxt[pre[pos]] = nxt[pos];
        pre[pos] = nxt[pos] = val[pos] = 0;
    }
    void remove_pt(int u) { remove(val_idx[u]); }
    void add_edge(int f, int u) { insert(pre[tail[f]], u); }
    void merge_list(int f, int u)
    {
        int last_f = pre[tail[f]], first_u = nxt[head[u]];
        nxt[last_f] = first_u, pre[first_u] = last_f;
        tail[f] = tail[u], head[u] = tail[u] = 0;
    }
}
namespace BIT
{
    int* rev_dfn;
    int n;
    inline int lowbit(int x) { return x & (-x); }
    int b[N];
    void build(int _n)
    {
        n = _n;
        for (int i = 1; i <= n; ++i)
        {
            int f = i + lowbit(i);
            b[i] += 1;
            if (f <= n)
                b[f] += b[i];
        }
    }
    void modify(int pos, int val)
    {
        for (int p = pos; p <= n; p += lowbit(p))
            b[p] += val;
    }
    int query(int pos)
    {
        int ret = 0;
        for (int p = pos; p; p -= lowbit(p))
            ret += b[p];
        return ret;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
}
namespace HLD
{
    int to[N], nxt[N], h[N], cnt;
    void add_edge(int u, int v) { to[++cnt] = v, nxt[cnt] = h[u], h[u] = cnt; }
    int rt, n;
    int f[N], sz[N], dep[N], son[N];
    int dfn[N], rev_dfn[N], top[N], dfst;
    void dfs1(int u, int fa) // initial : rt, 0
    {
        f[u] = fa, sz[u] = 1, dep[u] = dep[fa] + 1;
        for (int i = h[u]; i; i = nxt[i])
        {
            int v = to[i];
            if (v == fa)
                continue;
            dfs1(v, u), sz[u] += sz[v];
            if (sz[son[u]] < sz[v])
                son[u] = v;
        }
    }
    void dfs2(int u, int topf) // initial rt, rt
    {
        top[u] = topf, dfn[u] = ++dfst, rev_dfn[dfst] = u;
        if (son[u])
            dfs2(son[u], topf);
        for (int i = h[u]; i; i = nxt[i])
        {
            int v = to[i];
            if (v == f[u] || v == son[u])
                continue;
            dfs2(v, v);
        }
    }
    void build(int _rt, int _n)
    {
        n = _n, rt = _rt;
        dfs1(rt, 0), dfs2(rt, rt);
        BIT::rev_dfn = rev_dfn, BIT::build(n);
    }
    void modify(int u, int val) { BIT::modify(dfn[u], val); }
    int query_chain(int u, int v)
    {
        int ret = 0;
        while (top[u] ^ top[v])
        {
            if (dep[f[top[u]]] < dep[f[top[v]]])
                std::swap(u, v);
            ret += BIT::query(dfn[top[u]], dfn[u]);
            u = f[top[u]];
        }
        if (dep[u] > dep[v])
            std::swap(u, v);
        ret += BIT::query(dfn[u], dfn[v]);
        return ret;
    }
}
int tmp_son[N], son_cnt;
void op_1(int u)
{
    son_cnt = 0;
    for (int i = list::nxt[list::head[u]]; i != list::tail[u]; i = list::nxt[i])
        tmp_son[++son_cnt] = list::val[i], sz[u] += sz[list::val[i]] - 1, d[u] += d[list::val[i]], HLD::modify(list::val[i], -1);
    for (int i = 1; i <= son_cnt; ++i)
        list::remove_pt(tmp_son[i]), list::merge_list(u, tmp_son[i]);
    wr(sz[u]), putchar(' '), wr(d[u]), putchar('\n');
}
void op_2(int u) { wr(HLD::query_chain(1, u)), putchar('\n'); }
int main()
{
    i64 n = rd(), m = rd();
    list::init(n);
    for (int i = 2; i <= n; ++i)
        f[i] = rd(), HLD::add_edge(f[i], i), ++sz[f[i]], list::add_edge(f[i], i);
    for (int i = 1; i <= n; ++i)
        d[i] = rd();
    HLD::build(1, n);
    while (m--)
    {
        int op = rd(), u = rd();
        (op & 1) ? op_1(u) : op_2(u);
    }
}

// 作者：CYMario
// 链接：https://www.acwing.com/solution/content/250245/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。