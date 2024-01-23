#include <bits/stdc++.h>

using namespace std;

int main() {
  // ofstream cout("stacking.out");
  // ifstream cin("stacking.in");

  int N, K;

  cin >> N >> K;

  //
  // [0,1,-1,0]
  //

  int diff[N];
  memset(diff, 0x00, N * 4);

  for (int i = 0; i < K; i++) {
    int A, B;
    cin >> A >> B;

    diff[A - 1] += 1;
    diff[B - 1] -= 1;
  }

  int arr[N];

  int cur = 0;

  for (int i = 0; i < N; i++) {
    cur += diff[i];
    arr[i] = cur;
  }

  sort(arr, arr + N);

  cout << arr[N / 2] << endl;
}
