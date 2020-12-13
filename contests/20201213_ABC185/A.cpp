#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int ans = 100;
  for (int i = 0; i < 4; i++) {
    int x;
    cin >> x;
    ans = min(ans, x);
  }

  cout << ans << endl;

  return 0;
}