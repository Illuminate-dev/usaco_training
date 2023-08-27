/*
PROG: milk2
LANG: C++
ID: henrydb1
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream in("milk2.in");
  ofstream out("milk2.out");

  int n;

  in >> n;

  vector<pair<int, int>> vals;

  for (int i = 0; i < n; i++) {
    int start, end;
    in >> start >> end;
    vals.push_back(make_pair(start, end));
  }

  sort(vals.begin(), vals.end());

  int none = 0;
  int some = 0;

  int lastend = -1;
  int laststart = -1;

  // 300 to 500, 700 to 1200, 1500 to 2100
  //

  for (int i = 0; i < n; i++) {

    pair<int, int> p = vals[i];
    int start = p.first, end = p.second;

    if (start <= lastend) {
      lastend = max(lastend, end);
      laststart = min(start, laststart);
      some = max(some, lastend - laststart);
    } else {
      if (laststart > 0)
        none = max(none, start - lastend);
      some = max(some, end - start);
      lastend = end;
      laststart = start;
    }
  }

  out << some << " " << none << endl;
}
