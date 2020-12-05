#include <iostream>
using namespace std;

// S の中に T と一致するパターンがあるか確認する関数
bool search_pattern(const string &S, const string &T) {
  for (int i = 0; i < (int)S.size(); i++) {
    if (i + (int)T.size() - 1 > (int)S.size() - 1) return false;
    bool match = true;
    for (int j = 0; j < (int)T.size(); j++) {
      if (S[i + j] != T[j]) {
        match = false;
        break;
      }
    }
    if (match) return true;
  }
  return false;
}

int main() {
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

  // それ以外
  // Tより少し大きい110の列Sを作成
  string S;
  while ((int)S.size() - 2 < N) {
    S += "110";
  }

  if (search_pattern(S, T)) {
    // S の中に パターン T がある場合

    // 0 の数を数える
    int zero_cnt = 0;
    for (auto c : T) {
      if (c == '0') {
        zero_cnt++;
      }
    }

    if (T[T.size() - 1] == '0') {
      // T の末尾が0の場合、110 をまたがずにパターンを作ることができる
      cout << 10000000000 - zero_cnt + 1 << endl;
    } else {
      // 末尾が0でない場合、110をまたぐ
      cout << 10000000000 - zero_cnt << endl;
    }
  } else {
    // S の中に パターン T がない場合答えは 0
    cout << 0 << endl;
  }

  return 0;
}