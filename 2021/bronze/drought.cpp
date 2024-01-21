#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

#define ll long long

using namespace std;

int run() {
  int N;
  cin >> N;
  if (N == 1)
    return 0;

  vector<int> h(N);

  for (int i = 0; i < N; i++)
    cin >> h[i];

  int ans = 0;

  for (int j : {1, 2}) {
    for (int i = 1; i < N - 1; i++) {
      if (h[i - 1] < h[i]) {
        int dif = h[i] - h[i - 1];
        ans += 2 * dif;
        h[i] = h[i - 1];
        h[i + 1] -= dif;
      }
    }
    if (h[N - 1] > h[N - 2])
      return -1;
    reverse(h.begin(), h.end());
  }
  return h[0] < 0 ? -1 : ans;
}

int run_tests() {
  int T;
  cin >> T;
  while (T--) {
    cout << run() << endl;
  }
  return 0;
}

int main() { run_tests(); }
