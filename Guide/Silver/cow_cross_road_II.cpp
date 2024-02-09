#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {

  ofstream cout("maxcross.out");
  ifstream cin("maxcross.in");

  int N, K, B;
  cin >> N >> K >> B;

  int signals[100000];
  memset(signals, 0, sizeof(signals));
  int pre[100001];
  memset(signals, 0, sizeof(signals));

  for (int i = 0; i < B; i++) {
    int n;
    cin >> n;
    signals[n] = 1;
  }

  for (int i = 1; i <= N; i++) {
    pre[i] = pre[i - 1] + signals[i];
  }

  int ans = INT_MAX;
  for (int i = 1; i <= N - K; i++) {
    ans = min(ans, pre[i + K] - pre[i]);
  }

  cout << ans << endl;
}
