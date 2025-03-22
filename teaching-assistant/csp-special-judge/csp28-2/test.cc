#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;
int n, m;
int p[N], t[N];
int res[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d", &p[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d", &t[i]);

  int mx = 0;
  for (int i = 1; i <= m; i++) {
    if (p[i] == 0)
      res[i] = 1;
    else
      res[i] = res[p[i]] + t[p[i]];

    mx = max(mx, res[i] + t[i] - 1);
  }

  for (int i = 1; i < m; i++)
    printf("%d ", res[i]);
  printf("%d", res[m]);

  puts("");

  if (mx > n)
    return 0;

  memset(res, 0x3f, sizeof res);
  for (int i = m; i > 0; i--) {
    if (res[i] > n)
      res[i] = n + 1 - t[i];
    if (p[i] != 0)
      res[p[i]] = min(res[p[i]], res[i] - t[p[i]]);
  }

  for (int i = 1; i < m; i++)
    printf("%d ", res[i]);
  printf("%d\n", res[m]);

  return 0;
}

// 作者：大四萌新.
// 链接：https://www.acwing.com/solution/content/192436/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
