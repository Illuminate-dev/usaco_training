/*
LANG: C++
PROG: combo
ID: henrydb1
*/

#include <fstream>
#include <iostream>

using namespace std;

int j[3], m[3], n;

int dist(int x1, int x2) { return min(abs(x1 - x2), n - abs(x1 - x2)); }

bool checks_out_opt(int x, int slot) {
  return dist(x, j[slot]) <= 2 || dist(x, m[slot]) <= 2;
}

bool checks_out(int x, int y, int z) {
  return (dist(x, j[0]) <= 2 && dist(y, j[1]) <= 2 && dist(z, j[2]) <= 2) ||
         (dist(x, m[0]) <= 2 && dist(y, m[1]) <= 2 && dist(z, m[2]) <= 2);
}

int main() {
  ifstream cin("combo.in");
  ofstream cout("combo.out");

  cin >> n;

  for (int i = 0; i < 3; i++)
    cin >> j[i];
  for (int i = 0; i < 3; i++)
    cin >> m[i];

  int out = 0;

  for (int x = 1; x <= n; x++) {
    if (!checks_out_opt(x, 0))
      continue;
    for (int y = 1; y <= n; y++) {
      if (!checks_out_opt(y, 1))
        continue;
      for (int z = 1; z <= n; z++) {
        if (checks_out(x, y, z)) {
          out++;
        }
      }
    }
  }

  cout << out << endl;
}
