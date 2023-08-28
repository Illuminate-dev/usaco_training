/*
PROG: transform
ID: henrydb1
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;
int n;
bool pat[10][10];
bool pat_after[10][10];
bool pat_result[10][10];

// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15

void rotate() {
  for (int i = 0; i < n; i++) {
    for (int j = n - 1, j2 = 0; j >= 0; j--, j2++) {
      pat_result[i][j2] = pat[j][i];
    }
  }
}

void reflect() {
  for (int i = n - 1, i2 = 0; i >= 0; i--, i2++) {
    for (int j = 0; j < n; j++) {
      pat_result[j][i2] = pat[j][i];
    }
  }
}

bool isEqual() {
  bool r = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (r && pat_result[i][j] != pat_after[i][j])
        r = false;
      pat[i][j] = pat_result[i][j];
    }
  }
  return r;
}

int main() {
  ifstream in("transform.in");
  ofstream out("transform.out");

  in >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x;
      in >> x;
      pat[i][j] = x == '@';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x;
      in >> x;
      pat_after[i][j] = x == '@';
    }
  }

  rotate();
  if (isEqual()) {
    out << 1 << endl;
    return 0;
  }

  rotate();
  if (isEqual()) {
    out << 2 << endl;
    return 0;
  }

  rotate();
  if (isEqual()) {
    out << 3 << endl;
    return 0;
  }

  rotate();
  isEqual();
  reflect();
  if (isEqual()) {
    out << 4 << endl;
    return 0;
  }

  rotate();
  if (isEqual()) {
    out << 5 << endl;
    return 0;
  }

  rotate();
  if (isEqual()) {
    out << 5 << endl;
    return 0;
  }

  rotate();
  if (isEqual()) {
    out << 5 << endl;
    return 0;
  }

  rotate();
  isEqual();
  reflect();

  if (isEqual()) {
    out << 6 << endl;
    return 0;
  }

  out << 7 << endl;

  return 0;
}
