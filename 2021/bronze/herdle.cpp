#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int char_to_num(char c) { return c - 'A'; }

pair<int, int> run() {
  char grid[3][3];

  int charCount[26];
  fill(charCount, charCount + 26, 0);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> grid[i][j];
      charCount[char_to_num(grid[i][j])]++;
    }
  }

  vector<char> other_guesses;
  int num_green = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char c;
      cin >> c;
      if (grid[i][j] == c) {
        num_green++;
        charCount[char_to_num(c)]--;
        continue;
      } else {
        other_guesses.push_back(c);
      }
    }
  }

  int num_yellow = 0;
  for (char c : other_guesses) {
    if (charCount[char_to_num(c)] > 0) {
      charCount[char_to_num(c)]--;
      num_yellow++;
    }
  }
  cout << num_green << endl << num_yellow << endl;
  return make_pair(num_green, num_yellow);
}

int main() { run(); }
