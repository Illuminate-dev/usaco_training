#include <bits/stdc++.h>
#include <cstdio>

#define ll long long

using namespace std;

int main() {
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);
  int N;
  cin >> N;

  int first[7] = {0, -1, -1, -1, -1, -1, -1};
  int last[7] = {0, -1, -1, -1, -1, -1, -1};

  ll runningRemainder = 0;

  for (int i = 1; i <= N; i++) {
    ll id;
    cin >> id;

    runningRemainder = (id + runningRemainder) % 7;

    last[runningRemainder] = i;

    if (first[runningRemainder] == -1) {
      first[runningRemainder] = i;
    }
  }

  int max = 0;
  for (int i = 0; i < 7; i++) {
    if (last[i] != -1) {
      if (last[i] - first[i] > max) {
        max = last[i] - first[i];
      }
    }
  }

  cout << max << endl;
}
