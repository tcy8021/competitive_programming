#include <cmath>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;

  if (S.size() == 1) {
    cout << S[0] << endl;
    return 0;
  }

  int n = (1 << (S.size() - 1)) - 1;  // +のパターンの総数
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long tmp = S[0] - '0';
    // +の位置とSの添字の整合性を取るための変数
    int m = n - i;
    for (int j = 1; j < S.size(); j++) {
      if (m & (1 << (j - 1))) {
        ans += tmp;
        tmp = 0;
      }
      tmp = 10 * tmp + (S[j] - '0');
      // cout << "j = " << j << ", tmp = " << tmp << endl;
    }
    ans += tmp;
    // cout << "i = " << i << ", ans = " << ans << endl;
  }

  cout << ans << endl;

  return 0;
}