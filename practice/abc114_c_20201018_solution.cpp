#include <iostream>
using namespace std;

void func(long long &N, long long cur, int use, int &counter) {
  if (cur > N) {
    return;
  }

  if (use == 0b111) {
    counter++;
  }

  func(N, 10 * cur + 3, use | 0b001, counter);
  func(N, 10 * cur + 5, use | 0b010, counter);
  func(N, 10 * cur + 7, use | 0b100, counter);
}

int main() {
  long long N;
  cin >> N;
  int counter = 0;
  func(N, 0, 0, counter);
  cout << counter << endl;
  return 0;
}