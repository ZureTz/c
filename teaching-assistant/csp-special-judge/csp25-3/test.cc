// 100 points 数据点1~20
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 1000 + 10;
int l[MAXN];  // l[i]表示计算节点i属于的分区
int st[MAXN]; // st[i]表示计算节点i运行的任务数量
int n, m;     // n表示计算节点数目，m表示可用区数目
unordered_map<int, vector<int>>
    app_list;            // app_list[a]记录应用a所占用的计算节点的列表
                         // 如app_list[1]={2,3}表示应用1占用节点2,3
bool paa_st[MAXN];       // paa_st[i]表示paa是否占用计算节点i
bool pa_region_st[MAXN]; // pa_region_st[i]表示分区i是否满足亲和性

int find_na(int na, int pa, int paa, int paar) {
  // 过滤阶段:
  // 过滤出所有满足要求的计算节点
  // 若na==0则不用过滤，若na>0则需要过滤计算节点i所属的可用区l[i],需要满足l[i]==na
  // 若pa==0则不用过滤，若pa>0则需要满足所选节点分区属于应用pa所占用的计算节点的分区
  // 若paa==0则不用过滤，若paa>0则需要满足所选节点不能为应用paa所占用的节点
  // 若paar==0且当前没有选中节点，则将计算任务亲和性的条件去掉

  // 排序阶段：
  // 选择此时运行计算任务数量最少的计算节点
  // 选择编号最小的计算节点
  memset(pa_region_st, false, sizeof(pa_region_st));
  memset(paa_st, false, sizeof(paa_st));
  if (pa != 0) {
    vector<int> tmp = app_list[pa]; // 获取应用pa所占用的节点
    for (auto item : tmp) {
      pa_region_st[l[item]] = true; // 表示pa占用计算节点所属的分区
    }
  }
  if (paa != 0) {
    vector<int> tmp = app_list[paa]; // 获取应用paa所占用的节点
    for (auto item : tmp) {
      paa_st[item] = true; // 表示paa占用计算节点item
    }
  }
  int min_pos = -1;        // 选中的节点
  int min_st = 0x3f3f3f3f; // 节点的任务数量
  for (int i = 1; i <= n; i++) {
    if (st[i] < min_st && (na == 0 || l[i] == na) &&
        (pa == 0 || pa_region_st[l[i]] == true) &&
        (paa == 0 || paa_st[i] == false)) {
      min_pos = i;
      min_st = st[i];
    }
  }
  if (paar == 0) {
    if (min_pos == -1) // 表示之前没有选中节点
    {
      for (int i = 1; i <= n; i++) {
        if (st[i] < min_st && (na == 0 || l[i] == na) &&
            (pa == 0 || pa_region_st[l[i]] == true)) {
          min_pos = i;
          min_st = st[i];
        }
      }
    }
  }
  return min_pos;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }
  int g;
  cin >> g;
  for (int i = 0; i < g; i++) {
    int f, a, na, pa, paa, paar;
    cin >> f >> a >> na >> pa >> paa >> paar;
    vector<int> ans;
    for (int j = 0; j < f; j++) {
      int x =
          find_na(na, pa, paa,
                  paar); // 选择满足要求的计算节点x,将当次任务分配给计算节点x
      if (x == -1)       // 若x==-1,表示没有满足条件的节点
        ans.push_back(0);
      else {
        st[x]++; // 计算节点运行的任务数量+1
        ans.push_back(x);
        app_list[a].push_back(x); // 应用a需要占用计算节点x
      }
    }
    // for (auto c : ans)
    //   cout << c << ' ';
    for (int j = 0; j < ans.size() - 1; j++) {
      cout << ans[j] << ' ';
    }
    cout << ans[ans.size() - 1];
    cout << '\n';
  }
  return 0;
}