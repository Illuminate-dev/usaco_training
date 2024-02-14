#include <bits/stdc++.h>

using namespace std;

int N, K;

// row, col
pair<int, int> rotate_45(int i, int j) {

  int row = i + j;
  int length = row + row + 1;
  int start = (N * 2 - 1 - length) / 2;
  int col = j * 2 + start;
  return {row, col};
}

int main() {
  freopen("lazy.in", "r", stdin);
  freopen("lazy.out", "w", stdout);

  cin >> N >> K;

  int arr[N * 2 - 1][N * 2 - 1];
  int pre[N * 2 - 1][N * 2 - 1];

  for (int i = 0; i < N * 2 - 1; i++) {
    for (int j = 0; j < N * 2 - 1; j++) {
      arr[i][j] = 0;
      pre[i][j] = 0;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int x;
      cin >> x;

      pair<int, int> point = rotate_45(i, j);

      arr[point.first][point.second] = x;
    }
  }

  for (int i = 0; i < N * 2 - 1; i++) {
    for (int j = 0; j < N * 2 - 1; j++) {
      pre[i][j] = arr[i][j];
      if (i > 0) {
        pre[i][j] += pre[i - 1][j];
      }
      if (j > 0) {
        pre[i][j] += pre[i][j - 1];
      }
      if (i > 0 && j > 0) {
        pre[i][j] -= pre[i - 1][j - 1];
      }
    }
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      pair<int, int> point = rotate_45(i, j);
      int top = max(0, point.first - K);
      int bottom = min(N * 2 - 2, point.first + K);
      int left = max(0, point.second - K);
      int right = min(N * 2 - 2, point.second + K);

      int sum = pre[bottom][right];
      if (top > 0)
        sum -= pre[top - 1][right];
      if (left > 0)
        sum -= pre[bottom][left - 1];
      if (left > 0 && top > 0)
        sum += pre[top - 1][left - 1];
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;

  // for (int i = 0; i < N * 2 - 1; i++) {
  //   for (int j = 0; j < N * 2 - 1; j++) {
  //     cout << pre[i][j] << (pre[i][j] > 9 ? " " : "  ");
  //   }
  //   cout << endl;
  // }
}
