#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

/*  lcm2 (a, b) : 2整数版
    入力：整数 a, b
    出力：aとbの最小公倍数
*/
long long lcm2(long long a, long long b) {
  long long d = gcd(a, b);
  return a / d * b;
}

/* lcm (vec) : ベクトルでの多整数版
    入力：整数のベクトル vec
    出力：すべての要素の最小公倍数
*/
long long lcm(const int N) {
  long long l = 2;
  for (int i = 3; i <= N; i++) {
    l = lcm2(l, i);
  }
  return l;
}

int main() {
  int N;
  cin >> N;
  long long ans = lcm(N);
  cout << ans + 1 << endl;
  return 0;
}