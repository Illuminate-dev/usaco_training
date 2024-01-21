#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  int prefixsum[N];
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (i == 0) {
      prefixsum[i] = num;
    } else {
      prefixsum[i] = prefixsum[i - 1] + num;
    }
  }

  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;

    cout << prefixsum[r] - prefixsum[l];
  }
}
