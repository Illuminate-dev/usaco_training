/*
PROG: crypt1
ID: henrydb1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int isgooddigit[10];

bool isgoodnum(int num, int len) {
  while (num != 0) {

    if (!isgooddigit[num % 10])
      return false;

    num /= 10;
    len--;
  }
  return len == 0;
}

bool isgoodprod(int i, int j) {
  if (!isgoodnum(i, 3) || !isgoodnum(j, 2) || !isgoodnum(i * j, 4)) {
    return false;
  }

  while (j) {
    if (!isgoodnum(i * (j % 10), 3)) {
      return false;
    }

    j /= 10;
  }
  return true;
}

int main() {
  ifstream cin("crypt1.in");
  ofstream cout("crypt1.out");

  int n;
  cin >> n;

  for (int i = 0; i < 10; i++)
    isgooddigit[i] = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    isgooddigit[x] = 1;
  }

  int out = 0;

  for (int i = 100; i < 1000; i++) {
    for (int j = 10; j < 100; j++) {
      if (isgoodprod(i, j))
        out++;
    }
  }

  cout << out << endl;

  return 0;
}
