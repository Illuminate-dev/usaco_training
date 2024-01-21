#include <bits/stdc++.h>
#include <vector>

using namespace std;

int run() {
  int ans = 0, N;

  cin >> N;
  vector<int> a;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  while (true) {
    int test_num = a[0];

    vector<int> new_vec;
    a.push_back(a[0]);
    int i = 0;
    bool unsuccessful = false;
    while (i < N - 1) {
      if (a[i] == test_num) {
        new_vec.push_back(a[i]);
        i++;
        continue;
      }
      unsuccessful = true;
      if (a[i] + a[i + 1] > test_num) {
        break;
      }

      new_vec.push_back(a[i + 1] + a[i]);
      i += 2;
    }
    if (i == N - 1 && !unsuccessful) {

    } else if (i < N - 1)
  }

  return ans;
}

int main() {

  int T;
  cin >> T;

  while (T--) {
    cout << run() << endl;
  }
}
