#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ans = 1e9;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    while (A[i] % 2 == 0) {
      cnt++;
      A[i] /= 2;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}