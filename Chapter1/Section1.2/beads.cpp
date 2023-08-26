/*
PROG: beads
ID: henrydb1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream in("beads.in");
  ofstream out("beads.out");

  int n;
  string beads;
  in >> n >> beads;

  beads += beads;

  int output = 0;

  int running_max = 0;
  char running_type = 'r';

  int i = 0;
  while (i < n) {
    if (beads.at(i) == running_type || beads.at(i) == 'w') {
      running_max++;
    } else {
      int j_max = 0;
      char j_char = beads.at(i);
      for (int j = i; j < (n + (i - running_max)) &&
                      (j_char == beads.at(j) || beads.at(j) == 'w');
           j++) {
        j_max += 1;
      }

      output = max(output, j_max + running_max);

      running_max = 1;
      for (int j = i - 1; j >= 0 && beads.at(j) == 'w'; j--) {
        running_max++;
      }
      running_type = beads.at(i);
    }

    i++;
  }

  int j_max = 0;
  char j_char = beads.at(i);
  for (int j = i; j < (n + (i - running_max)) &&
                  (j_char == beads.at(j) || beads.at(j) == 'w');
       j++) {
    j_max += 1;
  }

  output = max(output, j_max + running_max);

  out << output << endl;
}
