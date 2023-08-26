/*
PROG: friday
LANG: C++
ID: henrydb1
  */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int startYear = 1900;

bool isLeapYear(int n) { return n % ((n % 100 == 0) ? 400 : 4) == 0; }

int main() {
  ifstream in("friday.in");
  ofstream out("friday.out");

  int n;

  in >> n;

  int day = 2;

  int output[7] = {0, 0, 0, 0, 0, 0, 0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 12; j++) {
      day = (day + 12) % 7;

      output[day]++;

      int add = months[j];
      if (isLeapYear(i + startYear) && j == 1) {
        add += 1;
      }

      day = (day + add - 12) % 7;
    }
  }

  for (int i = 0; i < 7; i++) {
    out << output[i] << (i == 6 ? "" : " ");
  }

  out << endl;
}
