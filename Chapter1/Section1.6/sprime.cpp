/*
ID: henrydb1
PROG: sprime
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int isprime(int n) {
  if (n == 2)
    return true;
  if (n % 2 == 0 || n == 1)
    return false;
  for (int i = 3; i * i <= n; i++)
    if (n % i == 0)
      return false;

  return true;
}

vector<int> gen(int len) {
  if (len == 0) {
    vector<int> v;
    v.push_back(0);
    return v;
  }

  vector<int> old = gen(len - 1);
  vector<int> v;

  for (int i = 0; i < old.size(); i++) {
    for (int d = 1; d <= 9; d++)
      if (isprime(old[i] * 10 + d))
        v.push_back(old[i] * 10 + d);
  }

  return v;
}

int main() {
  ifstream cin("sprime.in");
  ofstream cout("sprime.out");

  int n;
  cin >> n;

  vector<int> v = gen(n);

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
}
