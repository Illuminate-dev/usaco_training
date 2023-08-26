/*
ID: henrydb1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ifstream in("gift1.in");
  ofstream out("gift1.out");

  int NP;

  in >> NP;

  unordered_map<string, int> name_to_idx;
  string people[12];
  int money[12];

  for (int i = 0; i < NP; i++) {
    string name;
    in >> name;
    name_to_idx[name] = i;
    people[i] = name;
    money[i] = 0;
  }

  for (int j = 0; j < NP; j++) {
    string giver;
    in >> giver;

    int gift, NG;
    in >> gift >> NG;
    if (NG == 0 || gift == 0)
      continue;

    int each = gift / NG;
    int pocket = gift % NG;

    cout << giver << " gives " << NG << " people each " << each << " and keeps "
         << pocket << endl;

    for (int i = 0; i < NG; i++) {
      string name;
      in >> name;
      money[name_to_idx[name]] += each;
    }
    money[name_to_idx[giver]] += pocket - gift;
  }

  for (int i = 0; i < NP; i++) {
    out << people[i] << " " << money[i] << endl;
  }
}
