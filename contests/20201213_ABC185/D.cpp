#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  if (M == 0) {
    cout << 1 << endl;
    return 0;
  }

  vector<char> A(N, 'w');
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  sort(B.begin(), B.end());

  int stamp_size = N;
  int prev_blue = 0;
  map<int, int> white;
  for (int i = 0; i < M; i++) {
    A[B[i] - 1] = 'b';

    // stamp_size の更新
    if (0 < B[i] - prev_blue - 1 && B[i] - prev_blue - 1 < stamp_size) {
      stamp_size = B[i] - prev_blue - 1;
    }

    // white の区間の長さを追加
    if (0 < B[i] - prev_blue - 1) {
      white[B[i] - prev_blue - 1]++;
    }

    // prev_blue 更新
    prev_blue = B[i];
  }
  // stamp_size の更新
  if (0 < N - prev_blue && N - prev_blue < stamp_size) {
    stamp_size = N - prev_blue;
  }

  // white の区間の長さを追加
  if (0 < N - prev_blue) {
    white[N - prev_blue]++;
  }

  int ans = 0;
  for (auto p : white) {
    if (p.first % stamp_size == 0) {
      ans += (p.first / stamp_size) * p.second;
    } else {
      ans += (p.first / stamp_size + 1) * p.second;
    }
  }

  cout << ans << endl;

  return 0;
}