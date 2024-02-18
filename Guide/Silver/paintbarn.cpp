#include <bits/stdc++.h>

using namespace std;

const int MAX_WIDTH = 200;

int main() {
  int N, K;

  cin >> N >> K;

  int pre[MAX_WIDTH + 1][MAX_WIDTH + 1];
  int dif[MAX_WIDTH][MAX_WIDTH];
  for (int i = 0; i < MAX_WIDTH + 1; i++) {
    for (int j = 0; j < MAX_WIDTH + 1; j++)
      pre[i][j] = 0;
  }
  for (int i = 0; i < MAX_WIDTH; i++) {
    for (int j = 0; j < MAX_WIDTH; j++)
      dif[i][j] = 0;
  }

  for (int i = 0; i < N; i++) {
    // (x1, y1) is upper left, (x2, y2) is lower right
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    pre[x1][y1]++;
    pre[x2][y2]++;
    pre[x1][y2]--;
    pre[x2][y1]--;
  }

  int ans = 0;

  for (int i = 1; i < MAX_WIDTH + 1; i++) {
    for (int j = 1; j < MAX_WIDTH + 1; j++) {
      pre[i][j] = pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
      ans += pre[i][j] == K;
      if (pre[i][j] == K) {
        dif[i - 1][j - 1] = -1;
      } else if (pre[i][j] == K - 1) {
        dif[i - 1][j - 1] = 1;
      }
      dif[i - 1][j - 1] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
    }
  }

  int largest_area = 0;
  int prev_min = 0;

  for (int i = 0; i < MAX_WIDTH; i++) {
    for (int j = 0; j < MAX_WIDTH; j++) {
      largest_area = max(dif[i][j] - prev_min, largest_area);
      prev_min = min(prev_min, dif[i][j]);
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << pre[i][j] << (pre[i][j] >= 0 ? "  " : " ");
    }
    cout << endl;
  }
}
