#include <bits/stdc++.h>

using namespace std;

int sign(int x) {
  if (x > 0) {
    return 1;
  } else if (x < 0) {
    return -1;
  } else {
    return 0;
  }
}

int run() {
  int N;
  cin >> N;

  int p[100000], t[100000];

  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  int ans = 0;

  int i = 0;
  while (i < N) {
    int state = sign(t[i] - p[i]); // 1 if hot, -1 if cold, 0 if same
    int min = abs(t[i] - p[i]);
    if (state == 0) {
      i++;
      continue;
    }

    int j = i + 1;
    while (j < N) {
      if (sign(t[j] - p[j]) != state) {
        break;
      }
      if (abs(t[j] - p[j]) < min) {
        min = abs(t[j] - p[j]);
      }
      j++;
    }
    // cout << "i: " << i << " state: " << state << " min: " << min << " j: " <<
    // j
    //      << endl;

    for (int k = i; k < j; k++) {
      t[k] += -state * min;
    }
    ans += min;
  }

  cout << ans << endl;
  return ans;
}

int run_tests() {
  int T;
  cin >> T;
  int ans[T];
  for (int i = 0; i < T; i++) {
    ans[i] = run();
  }
  int realans[T];
  for (int i = 0; i < T; i++) {
    cin >> realans[i];
  }

  for (int i = 0; i < T; i++) {
    cout << "Case #" << i + 1 << ": " << ans[i] << endl;
    if (ans[i] != realans[i]) {
      cout << "Wrong answer, should be `" << realans[i] << "`" << endl;
    } else {
      cout << "passed" << endl;
    }
  }
  return 0;
}

int main() { run(); }
