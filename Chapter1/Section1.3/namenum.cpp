/*
PROG: namenum
LANG: C++
ID: henrydb1
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

char num_to_char[9][3] = {
    {'Z', 'Z', 'Z'}, {'A', 'B', 'C'}, {'D', 'E', 'F'},
    {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'},
    {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'},
};

bool can_form_name(string name, string digits) {
  if (digits.length() != name.length())
    return false;

  for (int i = 0; i < name.length(); i++) {
    int idx = digits[i] - '0' - 1;
    bool found = false;
    for (int j = 0; j < 3; j++) {
      if (!found && num_to_char[idx][j] == name[i])
        found = true;
    }
    if (!found)
      return false;
  }
  return true;
}

int main() {
  ofstream out("namenum.out");
  ifstream dict("dict.txt");
  ifstream in("namenum.in");

  std::string digits;
  in >> digits;

  string name;

  vector<string> output;

  while (dict >> name) {
    if (can_form_name(name, digits))
      output.push_back(name);
  }

  if (output.size() == 0) {
    out << "NONE" << endl;
    return 0;
  }
  for (int i = 0; i < output.size(); i++) {
    out << output[i] << endl;
  }
}
