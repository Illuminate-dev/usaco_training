#include <bits/stdc++.h>

using namespace std;

struct AC {
  int a, b, p, m;
};

int N, M;
int s[20], t[20], c[20];
int a[10], b[10], m[10], p[10];
int ans = 1e9;

int check(string solution) {
  int cold[101];
  memset(cold, 0, 101);
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < M; j++) {
      if (solution[j] == '1' && a[j] <= i && b[j] >= i) {
        cold[i] += p[j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = s[i]; j <= t[i]; j++) {
      if (cold[j] < c[i]) {
        return 1e9;
      }
    }
  }

  int price = 0;
  for (int i = 0; i < M; i++) {
    if (solution[i] == '1')
      price += m[i];
  }

  return price;
}

void search(string str) {
  if (str.size() == M) {

    ans = min(ans, check(str));
  } else {
    search(str + "1");
    search(str + "0");
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

  search("");
  cout << ans << endl;
}
