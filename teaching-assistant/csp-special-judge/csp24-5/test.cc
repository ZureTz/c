#include <algorithm>
#include <iostream>
#define i64 long long

const int N = 500010;
int n, K1, K2;
i64 ans;
int to[N << 1], nxt[N << 1], h[N], ecnt;
inline void add_edge(int u, int v) {
  to[++ecnt] = v, nxt[ecnt] = h[u], h[u] = ecnt;
}
inline void link(int u, int v) { add_edge(u, v), add_edge(v, u); }
// centroid
int sz[N], tot_sz;
bool done[N];
inline void calc_sz(int u, int f) {
  ++tot_sz, sz[u] = 1;
  for (int i = h[u]; i; i = nxt[i])
    if ((to[i] ^ f) && !done[to[i]])
      calc_sz(to[i], u), sz[u] += sz[to[i]];
}
inline int find_cen(int u, int f) {
  for (int i = h[u]; i; i = nxt[i]) {
    if (to[i] == f || done[to[i]])
      continue;
    else if (sz[to[i]] > tot_sz / 2)
      return find_cen(to[i], u);
  }
  return u;
}
inline int get_cen(int u, int f) {
  return tot_sz = 0, calc_sz(u, f), find_cen(u, f);
}
// query for y in point (x, y)
namespace BIT {
int n;
i64 a[N]; // query sum for p >= pos
inline int lb(int x) { return x & (-x); }
inline void add(int pos, i64 v) {
  if (pos > 0)
    for (int p = pos; p; p -= lb(p))
      a[p] += v;
}
inline int query(int pos) {
  if (pos > n)
    return 0;
  int ret = 0;
  for (int p = std::max(1, pos); p <= n; p += lb(p))
    ret += a[p];
  return ret;
}
} // namespace BIT
// point : (x, y)
// query : count for X >= x, Y >= y
// flag : 0 modify 1 query
struct query {
  int x, y;
  bool flag;
  query(int _x = 0, int _y = 0, bool _f = 0) : x(_x), y(_y), flag(_f) {}
  inline bool operator<(const query &o) const {
    return (x ^ o.x) ? (x > o.x) : (flag < o.flag);
  }
} qu[N << 1];
int qcnt, st;
inline void process_query(int st, int ed, int op) {
  if (st > ed)
    return;
  i64 query_ans = 0;
  std::sort(qu + st, qu + ed + 1);
  for (int i = st; i <= ed; ++i)
    (qu[i].flag) ? (void)(query_ans += BIT::query(qu[i].y))
                 : (void)(BIT::add(qu[i].y, 1));
  for (int i = st; i <= ed; ++i) // clear
    if (!qu[i].flag)
      BIT::add(qu[i].y, -1);
  ans += op * query_ans;
}
// mx, mn : max / min P(cen, u)
inline void dfs_query(int u, int f, int mx, int mn, int cen) {
  BIT::n = std::max(BIT::n, mx);
  if (mx <= u + K2)
    qu[++qcnt] = query(u, mn, 0);
  if (mn >= u - K1)
    qu[++qcnt] = query(std::max(u + 1, mx - K2), u - K1, 1);
  if (mx <= std::max(cen, u) + K2 && mn >= std::min(cen, u) - K1)
    ++ans;
  for (int i = h[u]; i; i = nxt[i])
    if (to[i] ^ f && !done[to[i]])
      dfs_query(to[i], u, std::max(mx, to[i]), std::min(mn, to[i]), cen);
}
inline void decompose(int u, int f) {
  int cen = get_cen(u, f);
  done[cen] = 1;
  st = 1, qcnt = 0;
  for (int i = h[cen]; i; i = nxt[i])
    if (to[i] ^ f && !done[to[i]]) {
      dfs_query(to[i], cen, std::max(cen, to[i]), std::min(cen, to[i]), cen);
      process_query(st, qcnt, -1), st = qcnt + 1;
    }
  process_query(1, qcnt, 1), BIT::n = 0;
  for (int i = h[cen]; i; i = nxt[i])
    if (to[i] ^ f && !done[to[i]])
      decompose(to[i], cen);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> K1 >> K2;
  for (int i = 1; i < n; ++i) {
    int t1, t2;
    std::cin >> t1 >> t2;
    link(t1, t2);
  }
  decompose(1, 0);
  std::cout << (ans + n) << std::endl;
}

// 作者：CYMario
// 链接：https://www.acwing.com/solution/content/253942/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。