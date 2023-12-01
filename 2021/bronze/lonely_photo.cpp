#include <bits/stdc++.h>

using namespace std;

#define ll long long

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

  ll ans = 0;
  int hidx = 0;
  int gidx = 0;
  for (int i = 0; i < N - 2; i++) {
    if (hidx < hIndex.size() && i > hIndex[hidx]) {
      hidx++;
    }
    if (gidx < gIndex.size() && i > gIndex[gidx]) {
      gidx++;
    }

    int curH, nextH;
    if (hidx < hIndex.size()) {
      curH = hIndex[hidx];
    } else {
      curH = N;
    }
    if (hidx + 1 < hIndex.size()) {
      nextH = hIndex[hidx + 1];
    } else {
      nextH = N;
    }

    int curG, nextG;
    if (gidx < gIndex.size()) {
      curG = gIndex[gidx];
    } else {
      curG = N;
    }
    if (gidx + 1 < gIndex.size()) {
      nextG = gIndex[gidx + 1];
    } else {
      nextG = N;
    }

    int subtractor = 0;
    if (nextH < curG && curG - i + 1 > 3) {
      int numHs = curG - i;
      subtractor = numHs - 2;
    } else if (nextG < curH && curH - i + 1 > 3) {
      int numGs = curH - i;
      subtractor = numGs - 2;
    }
    int len = max(nextH, nextG) - i;

    ans += len - 2 - subtractor;
  }

  cout << ans << endl;
}
