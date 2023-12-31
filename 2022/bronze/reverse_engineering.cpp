#include <bits/stdc++.h>

using namespace std;

string strings[100];
int output[100];
bool used[100];
int T, N, M;

bool split(int j, char comp, int out) {
  // try to say if (b[j] == comp return out)
  if (used[j])
    return false;

  for (int i = 0; i < M; i++) {
    if (!strings[i].empty() && strings[i][j] == comp && output[i] != out) {
      return false;
    }
  }

  used[j] = true;

  for (int i = 0; i < M; i++) {
    if (!strings[i].empty() && strings[i][j] == comp)
      strings[i] = "";
  }

  return true;
}

bool all_equal(int test_ans) {
  for (int i = 0; i < M; i++) {
    if (!strings[i].empty() && output[i] != test_ans)
      return false;
  }
  return true;
}

int main() {

  cin >> T;

  while (T--) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
      cin >> strings[i] >> output[i];
    }
    for (int j = 0; j < N; j++)
      used[j] = false;

    while (true) {
      bool split_found = false;

      for (int j = 0; j < N; j++) {
        if (split(j, '0', 0) || split(j, '1', 0) || split(j, '0', 1) ||
            split(j, '1', 1))
          split_found = true;
      }

      if (!split_found) {
        cout << "LIE\n";
        break;
      }

      if (all_equal(0) || all_equal(1)) {
        cout << "OK\n";
        break;
      }
    }
  }
}
