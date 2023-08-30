/*
PROG: dualpal
ID: henrydb1
LANG: C++
*/

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

bool is_palindrome(string x) {
  int l = 0, r = x.length() - 1;

  while (l < r) {
    if (x[l] != x[r])
      return false;
    l++;
    r--;
  }
  return true;
}

bool num_base_is_pal(int num, int base) {
  string x;
  while (num != 0) {
    x += (char)((num % base) - '0');
    num /= base;
  }

  reverse(x.begin(), x.end());

  return is_palindrome(x);
}

int main() {
  ifstream cin("dualpal.in");
  ofstream cout("dualpal.out");

  int n, s;

  cin >> n >> s;

  int n_c = 0;
  for (int i = s + 1; n_c < n; i++) {
    // loop for each possible base

    int b_c = 0;
    for (int b = 2; b_c < 2 && b <= 10; b++) {
      if (num_base_is_pal(i, b)) {
        b_c++;
      }
    }
    if (b_c >= 2) {
      cout << i << endl;
      n_c++;
    }
  }
}
