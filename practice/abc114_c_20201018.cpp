#include <iostream>
#include <vector>
using namespace std;

int res = 0;

bool check_753(int x) {
  string s = to_string(x);
  vector<bool> flags(3, false);
  for (char c : s) {
    if (c == '3') {
      flags[0] = true;
    } else if (c == '5') {
      flags[1] = true;
    } else if (c == '7') {
      flags[2] = true;
    } else {
      return false;
    }
  }

  return flags[0] && flags[1] && flags[2];
}

void make_753(long long x, int &N) {
  if (x > N) {
    return;
  }

  if (check_753(x)) {
    res++;
  }

  make_753(10 * x + 3, N);
  make_753(10 * x + 5, N);
  make_753(10 * x + 7, N);
}

int main() {
  int N;
  cin >> N;

  make_753(0, N);

  cout << res << endl;
}