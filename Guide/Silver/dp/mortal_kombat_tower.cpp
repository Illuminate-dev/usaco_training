// https://codeforces.com/problemset/problem/1418/C
#include <bits/stdc++.h>

using namespace std;

int run() {
  int N;
  cin >> N;
  int a[N];

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  // 0 - my turn, 1 - their turn
  int dp[2][N];

  for (int i = N - 1; i >= 0; i--) {
    if (i == N - 1) {
      dp[0][N - 1] = 0;
      dp[1][N - 1] = a[N - 1];
    } else if (i == N - 2) {
      dp[0][i] = 0;
      dp[1][i] = a[i];
    } else {
      dp[0][i] = min(dp[1][i + 1], dp[1][i + 2]);
      dp[1][i] = min(a[i] + dp[0][i + 1], a[i] + a[i + 1] + dp[0][i + 2]);
    }
  }

  cout << dp[1][0] << endl;

  return 0;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    run();
  }
}
