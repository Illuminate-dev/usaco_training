/*
ID: henrydb1
PROG: pprime
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

bool isPrime(long n) {

  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;

  for (long i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  ifstream cin("pprime.in");
  ofstream cout("pprime.out");

  int a, b;

  cin >> a >> b;

  // 1 dig
  for (int i = 5; i <= 9; i += 2) {
    if (i <= b && i >= a && isPrime(i))
      cout << i << endl;
  }
  // 2 dig
  for (int i = 1; i <= 9; i += 2) {
    int num = i * 10 + i;
    if (num <= b && num >= a && isPrime(num))
      cout << num << endl;
  }
  // 3 dig
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; j++) {
      int num = i * 100 + j * 10 + i;
      if (num <= b && num >= a && isPrime(num))
        cout << num << endl;
    }
  }
  // 4 dig
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; j++) {
      int num = i * 1000 + j * 100 + j * 10 + i;
      if (num <= b && num >= a && isPrime(num))
        cout << num << endl;
    }
  }
  // 5 dig
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        int num = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
        if (num <= b && num >= a && isPrime(num))
          cout << num << endl;
      }
    }
  }
  // 6 dig
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        int num = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i;
        if (num <= b && num >= a && isPrime(num))
          cout << num << endl;
      }
    }
  }
  // 7 dig
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        for (int l = 0; l <= 9; l++) {
          int num = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 +
                    j * 10 + i;
          if (num <= b && num >= a && isPrime(num))
            cout << num << endl;
        }
      }
    }
  }
  // 8 dig
  for (int i = 1; i <= 9; i += 2) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        for (int l = 0; l <= 9; l++) {
          int num = i * 10000000 + j * 1000000 + k * 100000 + l * 10000 +
                    l * 1000 + k * 100 + j * 10 + i;
          if (num <= b && num >= a && isPrime(num))
            cout << num << endl;
        }
      }
    }
  }
}
