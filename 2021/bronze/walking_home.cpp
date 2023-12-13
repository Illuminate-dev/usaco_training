#include <bits/stdc++.h>

using namespace std;

int N, K;
char area[50][50]; // (i, j)

// returns num of possible routes involving at most k_left turns
int dfs(int i, int j, int k_left, bool cur_dir_is_right) {
  if (k_left < 0 || i >= N || j >= N || area[i][j] == 'H') {
    return 0;
  }

  if (i == N - 1 && j == N - 1) {
    return 1;
  }

  return dfs(i + 1, j, k_left - (cur_dir_is_right ? 1 : 0), false) +
         dfs(i, j + 1, k_left - (cur_dir_is_right ? 0 : 1), true);
}

int run() {

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> area[i][j];
    }
  }

  int ans = dfs(1, 0, K, false) + dfs(0, 1, K, true);
  cout << ans << endl;
  return ans;
}

void run_tests() {
  int T;

  cin >> T;

  while (T--) {
    run();
  }
}

int main() { run_tests(); }
