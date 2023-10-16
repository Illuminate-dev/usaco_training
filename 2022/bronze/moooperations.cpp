#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  int ans = 1e9;
  if (s.length() < 3)
    return -1;
  for (int i = 1; i < s.length() - 1; i++) {
    if (s[i] == 'O') {
      ans =
          min(ans, (int)s.length() - 3 + (s[i - 1] != 'M') + (s[i + 1] != 'O'));
    }
  }
  return ans == 1e9 ? -1 : ans;
}

int main() {
  int Q;
  cin >> Q;
  while (Q--) {

    string s;
    cin >> s;

    cout << solve(s) << endl;
  }
}
