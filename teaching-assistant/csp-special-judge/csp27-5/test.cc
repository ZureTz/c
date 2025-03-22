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
i64 n, L;
int M[N];
i64 X[N], dp[N];
struct line {
  i64 k, b;
  inline line(i64 _k = 0, i64 _b = INF) : k(_k), b(_b) {}
  inline i64 f(const i64 &x) const { return k * x + b; }
} lin[N];
struct node_in {
  int lid, lc, rc;
} tri[N * LOG_N];
int icnt;
struct node_out {
  int rt, lc, rc;
} tro[N << 1];
int ocnt;
void modify_in(int &u, int l, int r, int lid) {
  if (!u)
    return (void)(u = ++icnt, tri[u].lid = lid);
  int m = (l + r) >> 1;
  if (lin[tri[u].lid].f(X[m]) > lin[lid].f(X[m]))
    std::swap(tri[u].lid, lid);
  if (lin[tri[u].lid].f(X[l]) > lin[lid].f(X[l]))
    modify_in(tri[u].lc, l, m, lid);
  else if (lin[tri[u].lid].f(X[r]) > lin[lid].f(X[r]))
    modify_in(tri[u].rc, m + 1, r, lid);
}
i64 query_in(const int rt, const int &x) {
  i64 ret = lin[tri[rt].lid].f(X[x]);
  int l = 0, r = n, m = 0, u = rt;
  while (l < r) {
    m = (l + r) >> 1;
    (x <= m) ? (u = tri[u].lc, r = m) : (u = tri[u].rc, l = m + 1);
    if (!u)
      return ret;
    ret = std::min(ret, lin[tri[u].lid].f(X[x]));
  }
  return ret;
}
int build_out(int l, int r) {
  int u = ++ocnt, m = (l + r) >> 1;
  if (l ^ r)
    tro[u].lc = build_out(l, m), tro[u].rc = build_out(m + 1, r);
  return u;
}
void modify_out(int u, int l, int r, int pos, int lid) {
  modify_in(tro[u].rt, 0, n, lid);
  if (l == r)
    return;
  int m = (l + r) >> 1;
  (pos <= m) ? (modify_out(tro[u].lc, l, m, pos, lid))
             : (modify_out(tro[u].rc, m + 1, r, pos, lid));
}
i64 query_out(int u, int L, int R, int l, int r, int x) {
  if (l > R || r < L)
    return INF;
  if (l <= L && R <= r)
    return query_in(tro[u].rt, x);
  int M = (L + R) >> 1;
  return std::min(query_out(tro[u].lc, L, M, l, r, x),
                  query_out(tro[u].rc, M + 1, R, l, r, x));
}
int main() {
  n = rd(), L = rd();
  build_out(0, n);
  for (int i = 1; i <= n; ++i)
    X[i] = rd() + X[i - 1];
  for (int i = 1; i <= n; ++i)
    M[i] = rd();
  lin[1] = line(-2 * X[0], dp[0] + 2 * X[0] * L + X[0] * X[0]);
  modify_out(1, 0, n, M[0], 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = query_out(1, 0, n, 0, M[i] - 1, i);
    dp[i] += (X[i] - L) * (X[i] - L);
    lin[i + 1] = line(-2 * X[i], dp[i] + 2 * X[i] * L + X[i] * X[i]);
    modify_out(1, 0, n, M[i], i + 1);
  }
  wr(dp[n]);
}

// 作者：CYMario
// 链接：https://www.acwing.com/solution/content/252851/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。