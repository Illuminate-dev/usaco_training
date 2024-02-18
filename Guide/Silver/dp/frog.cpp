#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int heights[N];
  for (int i = 0; i < N; i++)
    cin >> heights[i];

  int dp[N];

  for (int i = N - 1; i >= 0; i--) {
    if (N - i == 1) {
      dp[i] = 0;
    } else if (N - i == 2) {
      dp[i] = abs(heights[i] - heights[i + 1]);
    } else {
      dp[i] = min(dp[i + 1] + abs(heights[i] - heights[i + 1]),
                  dp[i + 2] + abs(heights[i] - heights[i + 2]));
    }
  }

  cout << dp[0] << endl;
}
