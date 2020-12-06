#include <iostream>
using namespace std;

int main() {
  // 入力
  int N;
  string T;
  cin >> N >> T;

  // 特殊なケースは先に答える
  if (T == "1") {
    cout << 20000000000 << endl;
    return 0;
  } else if (T == "11") {
    cout << 10000000000 << endl;
    return 0;
  }

  // Tより少し長い110の列Sを用意して、TがSの中に存在するか判定
  string S;
  while ((int)S.size() < N + 10) {
    S += "110";
  }

  int unmatch_cnt = 0;
  for (int i = 0; i < 3; i++) {
    if (T != S.substr(i, N)) {
      unmatch_cnt++;
    }
  }

  // Sの中にTが一致しなければ0を答える
  if (unmatch_cnt == 3) {
    cout << 0 << endl;
    return 0;
  }

  // Tが一致したら0の数を数えて答えを計算
  int zero_cnt = 0;
  for (auto c : T) {
    if (c == '0') {
      zero_cnt++;
    }
  }

  if (T[T.size() - 1] == '0') {
    cout << 10000000000 - zero_cnt + 1 << endl;
  } else {
    cout << 10000000000 - zero_cnt << endl;
  }

  return 0;
}