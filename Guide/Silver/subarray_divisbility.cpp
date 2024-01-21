#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int prev = 0;
  vector<int> count(n, 0);
  count[0]++;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    prev = (prev + num) % n;
    ans += count[prev];
    count[prev]++;
  }
  cout << ans << endl;
}
