#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin("hps.in");
  ofstream cout("hps.out");

  int N;
  cin >> N;

  int hoof_pre[N + 1];
  hoof_pre[0] = 0;
  int paper_pre[N + 1];
  paper_pre[0] = 0;
  int scissors_pre[N + 1];
  scissors_pre[0] = 0;

  for (int i = 0; i < N; i++) {
    char move;
    cin >> move;
    switch (move) {
    case 'H':
      hoof_pre[i + 1] = hoof_pre[i] + 1;
      paper_pre[i + 1] = paper_pre[i];
      scissors_pre[i + 1] = scissors_pre[i];
      break;
    case 'P':
      paper_pre[i + 1] = paper_pre[i] + 1;
      scissors_pre[i + 1] = scissors_pre[i];
      hoof_pre[i + 1] = hoof_pre[i];
      break;
    case 'S':
      scissors_pre[i + 1] = scissors_pre[i] + 1;
      paper_pre[i + 1] = paper_pre[i];
      hoof_pre[i + 1] = hoof_pre[i];
      break;
    }
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    int max_pre =
        max(max(hoof_pre[i + 1], paper_pre[i + 1]), scissors_pre[i + 1]);
    int max_post = max(max(hoof_pre[N] - hoof_pre[i + 1],
                           scissors_pre[N] - scissors_pre[i + 1]),
                       paper_pre[N] - paper_pre[i + 1]);

    ans = max(ans, max_post + max_pre);
  }

  cout << ans << endl;
}
