#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();

  long long res = 0;
  for (int i = 0; i < (1 << (N - 1)); i++) {
    long long tmp = 0;
    for (int j = 0; j < N - 1; j++) {
      tmp *= 10;
      tmp += S[j] - '0';
      if (i & (1 << j)) {
        res += tmp;
        tmp = 0;
      }
    }

    tmp *= 10;
    tmp += S.back() - '0';
    res += tmp;
  }

  cout << res << endl;
}