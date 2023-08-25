/*
ID: henrydb1
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int getNum(string x) {
  int out = 1;
  for (int i = 0; i < x.length(); i++) {
    out *= x[i] - 'A' + 1;
  }
  return out;
}

int main() {
  ifstream fin("ride.in");
  ofstream fout("ride.out");
  string comet, group;
  fin >> comet >> group;

  int c = getNum(comet);
  int g = getNum(group);

  if (c % 47 == g % 47) {
    fout << "GO" << endl;
  } else {
    fout << "STAY" << endl;
  }

  return 0;
}
