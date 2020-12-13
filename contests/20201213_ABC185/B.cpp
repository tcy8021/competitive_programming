#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, T;
  cin >> N >> M >> T;
  int n = N;
  int t = 0;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    n -= a - t;
    if (n <= 0) {
      cout << "No" << endl;
      return 0;
    }
    n = min(N, n + (b - a));
    t = b;
  }

  n -= T - t;
  if (n <= 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}