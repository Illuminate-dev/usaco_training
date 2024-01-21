#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {

  ifstream cin("bcount.in");
  ofstream cout("bcount.out");

  int n, q;
  cin >> n >> q;

  int hSum[n + 1];
  int gSum[n + 1];

  int x;
  hSum[0] = 1;
  gSum[0] = 1;

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      hSum[i] = hSum[i - 1] + 1;
      gSum[i] = gSum[i - 1];
    } else if (x == 2) {
      gSum[i] = gSum[i - 1] + 1;
      hSum[i] = hSum[i - 1];
    } else {
      hSum[i] = hSum[i - 1];
      gSum[i] = gSum[i - 1];
    }
  }

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;

    int h = hSum[b] - hSum[a - 1];
    int g = gSum[b] - gSum[a - 1];
    int j = b - h - g - a + 1;

    cout << h << " " << g << " " << j << endl;
  }
  return 0;
}
