#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N;
ll K;

int main() {
  cin >> N >> K;

  ll lastday;
  cin >> lastday;
  ll currentval = K + 1;

  for (int i = 1; i < N; i++) {
    ll d;
    cin >> d;

    // is it worth it to buy a (d-lastday) subscription
    if (d - lastday < K + 1)
      currentval += d - lastday;
    else
      currentval += K + 1;
    lastday = d;
  }

  cout << currentval << endl;
}
