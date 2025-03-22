#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>

#define x first
#define y second

using namespace std;

typedef long long LL;

int T;
pair<int, int> loc[65];
int q[9][9], m[9][9];
int m_q[9][9];
double m_[9][9];
int n;
int m_r[9][9];

double alfha(int u) //  阿尔法函数
{
  if (u == 0)
    return sqrt(1.0 / 2);
  else
    return 1.0;
}

double cal_cos(int i, int j) //  离散余弦逆变换
{
  double sum = 0;
  for (int u = 0; u < 8; u++)
    for (int v = 0; v < 8; v++) {
      sum += alfha(u) * alfha(v) * m_q[u][v] *
             cos(acos(-1) * (i + 1.0 / 2) * u / 8) *
             cos(acos(-1) * (j + 1.0 / 2) * v / 8);
    }
  return sum / 4.0;
}

int trans(double x) //  四舍五入
{
  if (x - (int)x >= 0.5)
    return x + 1;
  else
    return x;
}

int main() {
  loc[1] = make_pair(0, 0);
  loc[2] = make_pair(0, 1);
  loc[3] = make_pair(1, 0);
  loc[4] = make_pair(2, 0);
  loc[5] = make_pair(1, 1);
  loc[6] = make_pair(0, 2);
  loc[7] = make_pair(0, 3);
  loc[8] = make_pair(1, 2);
  loc[9] = make_pair(2, 1);
  loc[10] = make_pair(3, 0);
  loc[11] = make_pair(4, 0);
  loc[12] = make_pair(3, 1);
  loc[13] = make_pair(2, 2);
  loc[14] = make_pair(1, 3);
  loc[15] = make_pair(0, 4);
  loc[16] = make_pair(0, 5);
  loc[17] = make_pair(1, 4);
  loc[18] = make_pair(2, 3);
  loc[19] = make_pair(3, 2);
  loc[20] = make_pair(4, 1);
  loc[21] = make_pair(5, 0);
  loc[22] = make_pair(6, 0);
  loc[23] = make_pair(5, 1);
  loc[24] = make_pair(4, 2);
  loc[25] = make_pair(3, 3);
  loc[26] = make_pair(2, 4);
  loc[27] = make_pair(1, 5);
  loc[28] = make_pair(0, 6);
  loc[29] = make_pair(0, 7);
  loc[30] = make_pair(1, 6);
  loc[31] = make_pair(2, 5);
  loc[32] = make_pair(3, 4);
  loc[33] = make_pair(4, 3);
  loc[34] = make_pair(5, 2);
  loc[35] = make_pair(6, 1);
  loc[36] = make_pair(7, 0);
  loc[37] = make_pair(7, 1);
  loc[38] = make_pair(6, 2);
  loc[39] = make_pair(5, 3);
  loc[40] = make_pair(4, 4);
  loc[41] = make_pair(3, 5);
  loc[42] = make_pair(2, 6);
  loc[43] = make_pair(1, 7);
  loc[44] = make_pair(2, 7);
  loc[45] = make_pair(3, 6);
  loc[46] = make_pair(4, 5);
  loc[47] = make_pair(5, 4);
  loc[48] = make_pair(6, 3);
  loc[49] = make_pair(7, 2);
  loc[50] = make_pair(7, 3);
  loc[51] = make_pair(6, 4);
  loc[52] = make_pair(5, 5);
  loc[53] = make_pair(4, 6);
  loc[54] = make_pair(3, 7);
  loc[55] = make_pair(4, 7);
  loc[56] = make_pair(5, 6);
  loc[57] = make_pair(6, 5);
  loc[58] = make_pair(7, 4);
  loc[59] = make_pair(7, 5);
  loc[60] = make_pair(6, 6);
  loc[61] = make_pair(5, 7);
  loc[62] = make_pair(6, 7);
  loc[63] = make_pair(7, 6);
  loc[64] = make_pair(7, 7);
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      cin >> q[i][j];
  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    m[loc[i].x][loc[i].y] = a;
  }
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      m_q[i][j] = m[i][j] * q[i][j];
  if (T == 0) //  扫描
  {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8 - 1; j++)
        cout << m[i][j] << ' ';
      cout << m[i][8 - 1] << endl;
    }
  } else if (T == 1) //  量化
  {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8 - 1; j++)
        cout << m[i][j] * q[i][j] << ' ';
      cout << m[i][8 - 1] * q[i][8 - 1] << endl;
    }
  } else //  离散逆变换
  {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        m_[i][j] = cal_cos(i, j);
        m_r[i][j] = trans(m_[i][j] + 128);
      }
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8 - 1; j++) {
        if (m_r[i][j] > 255)
          cout << "255" << ' ';
        else if (m_r[i][j] < 0)
          cout << "0" << ' ';
        else
          cout << m_r[i][j] << ' ';
      }
      if (m_r[i][8 - 1] > 255)
        cout << "255";
      else if (m_r[i][8 - 1] < 0)
        cout << "0";
      else
        cout << m_r[i][8 - 1];
      cout << endl;
    }
  }
  return 0;
}

// 作者：B_ay
// 链接：https://www.acwing.com/solution/content/203877/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
