/*
PROG: ariprog
LANG: C++
ID: henrydb1
*/

#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int m, n, maxM;
bool bisqr[62501] = {false};
bool available[125001] = {false};
int numbers[65000];

int main() {
  ifstream cin("ariprog.in");
  ofstream cout("ariprog.out");

  cin >> m >> n;

  int num_idx = 0;

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      int n = i * i + j * j;
      if (!bisqr[n]) {

        bisqr[n] = true;
        numbers[num_idx++] = n;
      }
    }
  }

  sort(numbers, numbers + num_idx);

  maxM = m * m + m * m;

  for (int i = 0; i < num_idx; i++) {
    int num = numbers[i];
    for (int j = i + 1;
         j < num_idx && num + (numbers[j] - num) * (n - 1) <= maxM; j++) {
      if (bisqr[num + (numbers[j] - num) * (n - 1)] &&
          bisqr[num + (numbers[j] - num) * (n - 2)])
        available[numbers[j] - num] = true;
    }
  }

  int skipstep = 1;
  int num_res = 0;

  for (int i = 1; i < maxM; i += skipstep) {
    if (available[i]) {

      for (int p = 0; p < num_idx && numbers[p] + (n - 1) * i <= maxM; p++) {
        bool t = true;
        for (int k = 1; k < n; k++) {
          t &= (available[numbers[p] + k * i]);
        }
        if (!t)
          continue;
        cout << numbers[p] << " " << i << endl;
        num_res++;
        if (num_res == 1)
          skipstep = i;
      }
    }
  }

  return 0;
}
