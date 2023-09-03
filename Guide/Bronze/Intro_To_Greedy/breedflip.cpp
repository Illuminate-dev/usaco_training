/*
PROG: breedflip
ID: henrydb1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream in("breedflip.in");
  ofstream out("breedflip.out");

  int n;
  in >> n;

  string a, b;

  in >> a >> b;

  bool mismatched = false;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (!mismatched) {
        mismatched = true;
        ans++;
      }
    } else {
      mismatched = false;
    }
  }

  out << ans << endl;
  return 0;
}
