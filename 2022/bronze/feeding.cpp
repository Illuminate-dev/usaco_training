#include <bits/stdc++.h>

using namespace std;

int T, N, K;
int last_g, last_h;

int main() {
  cin >> T;
  while (T--) {
    cin >> N >> K;
    string s;
    cin >> s;
    string t(N, '.');

    last_g = last_h = -K - 1;
    int count = 0;
    for (int i = 0; i < N; i++) {
      if (s[i] == 'H' && (i - last_h > K)) {
        last_h = min(i + K, N - 1);
        if (t[last_h] != '.')
          last_h--;
        t[last_h] = 'H';
        count++;
      } else if (s[i] == 'G' && (i - last_g > K)) {
        last_g = min(i + K, N - 1);
        if (t[last_g] != '.')
          last_g--;
        t[last_g] = 'G';
        count++;
      }
    }

    cout << count << endl;
    cout << t << endl;
  }
}
