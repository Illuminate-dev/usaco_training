#include <bits/stdc++.h>

using namespace std;

int N, M;
int s[20], t[20], c[20];
int a[10], b[10], p[10], m[10];
int ans = 1e9;

int check(string sol) {
  int stalls[101] = {0};
  for (int i = 0; i < M; i++) {
    if (sol[i] == '1') {
      for (int j = a[i]; j <= b[i]; j++)
        stalls[j] += p[i];
    }
  }
  bool works = true;
  for (int i = 0; i < M; i++) {
    for (int j = s[i]; j <= t[i]; j++) {
      if (stalls[j] < c[i]) {
        works = false; // check if comfortable
      }
    }
  }
  int price = 0;
  for (int i = 0; i < sol.size(); i++) {
    if (sol[i] == '1')
      price += m[i]; // calculate price of conditioners used
  }
  if (works)
    return price;
  return 1e9; // does not work
}

void solve(string sol) {
  if (sol.length() == M) {
    ans = min(ans, check(sol));
  } else {
    solve(sol + "1");
    solve(sol + "0");
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> t[i] >> c[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i] >> p[i] >> m[i];
  }

  solve("");
  cout << ans << endl;
}
