#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAX_DAYS = 100000;

int N;
ll T;

ll min(ll a, ll b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

ll max(ll a, ll b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  cin >> N >> T;

  ll total = 0;
  ll remaining = 0;
  ll lastday = 0;

  // total, remaining are after the lastday has passed

  for (ll i = 0; i < N; i++) {
    ll day;
    ll bales;
    cin >> day >> bales;

    // calculate how many bales after day has passed
    total += bales;
    remaining -= day - lastday;
    lastday = day;
    remaining = max(remaining, 0) + bales;
  }

  remaining -= T + 1 - lastday;
  remaining = max(remaining, 0);

  cout << total - remaining << endl;
}
