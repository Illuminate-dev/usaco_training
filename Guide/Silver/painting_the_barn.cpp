#include <bits/stdc++.h>

using namespace std;

int WIDTH = 1001;

int main() {
  // ofstream cout("paintbarn.out"); ifstream cin("paintbarn.in");

  int N, K;
  cin >> N >> K;

  int pre[WIDTH + 1][WIDTH + 1];
  memset(pre, 0, (WIDTH + 1) * (WIDTH + 1) * 4);

  for (int i = 0; i < N; i++) {
    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;

    pre[start_x + 1][start_y + 1]++;
    pre[start_x + 1][end_y + 1]--;
    pre[end_x + 1][start_y + 1]--;
    pre[end_x + 1][end_y + 1]++;
  }

  int ans = 0;

  for (int x = 1; x < 10; x++) {
    for (int y = 1; y < 10; y++) {
      cout << pre[x][y] << ((pre[x][y] < 0) ? " " : "  ");
    }
    cout << endl;
  }

  for (int x = 1; x < WIDTH; x++) {
    for (int y = 1; y < WIDTH; y++) {
      pre[x][y] += pre[x - 1][y] + pre[x][y - 1] - pre[x - 1][y - 1];
      ans += pre[x][y] == K;
    }
  }

  for (int x = 1; x < 10; x++) {
    for (int y = 1; y < 10; y++) {
      cout << pre[x][y] << ((pre[x][y] < 0) ? " " : "  ");
    }
    cout << endl;
  }

  // for (int i = 0; i < WIDTH; i++)

  cout << ans << endl;
}
