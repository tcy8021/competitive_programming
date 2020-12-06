#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class UnionFind {
 public:
  vector<int> par, siz;

  UnionFind(int n) : par(n, -1), siz(n, 1) {}

  int root(int v) {
    if (par[v] == -1) {
      return v;
    } else {
      return root(par[v]);
    }
  }

  bool unite(int v, int u) {
    if (root(v) == root(u)) {
      return false;
    }

    v = root(v);
    u = root(u);
    if (siz[v] < siz[u]) {
      swap(v, u);
    }
    par[u] = v;
    siz[v] += siz[u];

    return true;
  }

  bool issame(int v, int u) { return root(v) == root(u); }

  int size(int v) { return siz[root(v)]; }
};

int main() {
  // 入力
  int N, M;
  vector<pair<int, int>> e;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    e.push_back(make_pair(a - 1, b - 1));
  }

  // 各辺が入力されていないと仮定し,
  // Union-Find で根が同じになるか判定する
  int ans = 0;
  for (int i = 0; i < M; i++) {
    UnionFind uf(N);
    int v, u;
    for (int j = 0; j < M; j++) {
      if (i == j) {
        // 辺の両端の頂点を記録して入力をスキップ
        v = e[j].first;
        u = e[j].second;
        continue;
      }
      uf.unite(e[j].first, e[j].second);
    }

    if (!uf.issame(v, u)) {
      // スキップした辺の両端の頂点が同じ根を持たなければその辺は橋である
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}