#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void comb(vector<vector<long long int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int k = 1; k < v.size(); k++) {
    for (int j = 1; j < k; j++) {
      v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
    }
  }
}

int main() {
  int L;
  cin >> L;
  vector<vector<long long>> v(L + 1, vector<long long>(L + 1, 0));
  comb(v);
  cout << v[L - 1][11] << endl;

  return 0;
}