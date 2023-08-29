/*
PROG: palsquare
ID: henrydb1
LANG: C++
*/

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const static int N = 301;
int B;

bool is_palindrome(string s1) {
  int l = 0, r = s1.length() - 1;
  while (l < r) {
    if (s1[l] != s1[r])
      return false;
    l++;
    r--;
  }
  return true;
}

char num_to_val(int num) {
  if (num >= 0 && num <= 9)
    return (char)(num + '0');
  else
    return (char)(num - 10 + 'A');
}

string to_base(int num) {
  string res = "";

  while (num > 0) {
    res += num_to_val(num % B);

    num /= B;
  }

  reverse(res.begin(), res.end());

  return res;
}

int main() {
  ifstream in("palsquare.in");
  ofstream out("palsquare.out");

  in >> B;

  pair<string, string> output[300];
  int j = 0;

  for (int i = 1; i < N; i++) {
    string sqr = to_base(i * i);
    if (is_palindrome(sqr))
      output[j++] = make_pair(to_base(i), sqr);
  }

  for (int i = 0; i < j; i++) {
    out << output[i].first << " " << output[i].second << endl;
  }
  return 0;
}
