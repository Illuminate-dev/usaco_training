#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdio>

using namespace std;

const int MAX_DAYS = 1000;

int main() {
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);

  int N, M, C;
  cin >> N >> M >> C;

  int m[N];

  for (int i = 0; i < N; i++)
    cin >> m[i];

  vector<vector<int>> roads(N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    roads[a - 1].push_back(b - 1);
  }

  vector<vector<int>> dp(MAX_DAYS + 1, vector<int>(N, -1));
  dp[0][0] = 0;

  int ans = 0;

  for (int i = 0; i < MAX_DAYS; i++) {
    for (int j = 0; j < N; j++) {
      if (dp[i][j] != -1) {
        for (int city : roads[j]) {
          dp[i + 1][city] = max(dp[i][j] + m[city], dp[i + 1][j]);
        }
      }
    }

    ans = max(ans, dp[i][0] - (C * i * i));
  }

  cout << ans << endl;
}
