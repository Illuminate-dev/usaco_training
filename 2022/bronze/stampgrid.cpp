#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
  cin >> T;
  while (T--) {
    int N;
    int K;
    char grid[20][20];
    char stamp[4][20][20];
    char generated[20][20];
    cin >> N;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> grid[i][j];
      }
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        cin >> stamp[0][i][j];
        stamp[1][j][K - i - 1] = stamp[0][i][j];
        stamp[2][K - i - 1][K - j - 1] = stamp[0][i][j];
        stamp[3][K - j - 1][i] = stamp[0][i][j];
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        generated[i][j] = '.';
      }
    }

    for (int rotation = 0; rotation < 4; rotation++) {
      for (int left = 0; left + K <= N; left++) {
        for (int top = 0; top + K <= N; top++) {
          // see if this stamp stamps it
          bool passed = true;
          for (int i = 0; i < K && passed; i++) {
            for (int j = 0; j < K && passed; j++) {
              if (stamp[rotation][i][j] == '*' &&
                  grid[i + left][j + top] == '.')
                passed = false;
            }
          }

          if (passed) {
            for (int i = 0; i < K; i++) {
              for (int j = 0; j < K; j++) {
                if (stamp[rotation][i][j] == '*') {
                  generated[i + left][j + top] = '*';
                }
              }
            }
          }
        }
      }
    }

    bool passed = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] != generated[i][j]) {
          passed = false;
        }
      }
    }

    if (passed)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
