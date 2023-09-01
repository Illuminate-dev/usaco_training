/*
PROG: barn1
ID: henrydb1
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
int a[200];

struct comparator {
  bool operator()(int lhs, int rhs) {
    return (a[lhs] - a[lhs - 1]) > (a[rhs] - a[rhs - 1]);
  }
};

int main() {
  ifstream cin("barn1.in");
  ofstream cout("barn1.out");
  int m, s, c;
  // idx i is the run between i and i-1
  // ex: 1 is the run between 0th and 1st elements
  int runs[200];

  cin >> m >> s >> c;

  for (int i = 0; i < c; i++) {
    int idx;
    cin >> idx;
    a[i] = idx;
  }

  for (int i = 0; i < c - 1; i++) {
    runs[i] = i + 1;
  }

  sort(a, a + c);
  sort(runs, runs + c - 1, comparator());

  int ans = a[c - 1] - a[0] + 1;

  for (int i = 1; i < m && i < c; i++) {
    // find max run
    int idx = runs[i - 1];

    int sub = a[idx] - a[idx - 1];
    if (sub == 0)
      break;
    ans -= (sub - 1);
  }

  cout << ans << endl;

  return 0;
}
