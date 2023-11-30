#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  string cows;
  cin >> N >> cows;

  vector<int> hIndex;
  vector<int> gIndex;
  for (int i = 0; i < N; i++) {
    if (cows[i] == 'H') {
      hIndex.push_back(i);
    } else {
      gIndex.push_back(i);
    }
  }

  int ans = 0;
  int nextHIndexIndex = 0;
  int nextGIndexIndex = 0;
  for (int i = 0; i < N - 2; i++) {
  }
}
