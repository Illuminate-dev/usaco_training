/*
ID: henrydb1
PROG: numtri
LANG: C++
*/

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream cout("numtri.out");
  ifstream cin("numtri.in");
  int R;

  cin >> R;

  int best[1000], oldbest[1000];

  for (int i = 0; i < 1000; i++)
    best[i] = 0;

  for (int i = 1; i <= R; i++) {
    memmove(oldbest, best, sizeof(oldbest));
    for (int j = 0; j < i; j++) {
      int n;
      cin >> n;
      if (j == 0)
        best[j] = oldbest[j] + n;
      else
        best[j] = max(oldbest[j], oldbest[j - 1]) + n;
    }
  }

  int m = 0;
  for (int i = 0; i < R; i++)
    if (best[i] > m)
      m = best[i];

  cout << m << endl;
}
