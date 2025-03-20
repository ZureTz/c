#include <bits/stdc++.h>
#include <iostream>

int rd() {
  int t;
  std::cin >> t;
  return t;
}

void wr(int t) { std::cout << t; }

const int N = 100010;
int n, k;
int a[N], s[N];
bool judge(int x, int l, int r, int tar) // target count of set
{
  int tmp = 0, cnt = 0;
  for (int i = l; i <= r; ++i) {
    if (tmp + a[i] >= x)
      ++cnt, tmp = 0;
    else
      tmp += a[i];
  }
  return cnt >= tar;
}
int solve_odd(int l, int r, int cnt) // z first cnt whole count
{
  int lo = 1, hi = (s[r] - s[l - 1]) + 1;
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    judge(mi, l, r, (cnt + 1) / 2) ? (lo = mi + 1) : (hi = mi);
  }
  return lo - 1;
}
int solve_even(int l, int r, int cnt) {
  int ans = s[r] - s[l - 1] + 1;
  for (int i = l + (cnt / 2); i <= r; ++i)
    ans = std::min(ans, s[i] - s[i - ((cnt / 2) + 1)]);
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  n = rd(), k = rd();
  for (int i = 1; i <= n; ++i)
    a[i] = rd(), s[i] = s[i - 1] + a[i];
  if (k)
    wr((n & 1) ? solve_odd(1, n, n) : solve_even(1, n, n));
  else
    wr((n & 1) ? std::min(solve_even(1, n - 1, n - 1), solve_even(2, n, n - 1))
               : std::min(solve_odd(1, n - 1, n - 1), solve_odd(2, n, n - 1)));
}

// 作者：CYMario
// 链接：https://www.acwing.com/solution/content/250269/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。