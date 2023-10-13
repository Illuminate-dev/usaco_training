#include <bits/stdc++.h>

using namespace std;

int N;
int h[200000];
int roads[200000];
int main() {
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
    sum += h[i];
  }

  int each = sum / N;

  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    roads[x] = y;
    roads[y] = x;
  }
}
