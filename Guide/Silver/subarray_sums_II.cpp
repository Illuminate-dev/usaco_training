#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  ll pre[n + 1];
  memset(pre, 0, n + 1);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    pre[i + 1] = num + pre[i];
  }

  ll ans = 0;
  unordered_map<ll, int> m;
  m.insert({0, 1});

  for (int i = 0; i < n; i++) {
    std::unordered_map<ll, int>::const_iterator count = m.find(pre[i + 1] - x);

    if (count != m.end()) {
      ans += count->second;
    }

    pair<std::unordered_map<ll, int>::iterator, bool> p =
        m.insert({pre[i + 1], 1});
    if (!p.second) {
      p.first->second += 1;
    }
  }

  cout << ans << endl;
}
