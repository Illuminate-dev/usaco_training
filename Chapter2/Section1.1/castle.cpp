/*
ID: henrydb1
PROG: castle
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int castle[50][50];
int group[50][50];
const static int NO_GROUP = 0;
const static int FIRST_GROUP = 1;
const static int VISITED = -1;

pair<int, int> dirs[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool better_place(pair<int, int> coord1, pair<int, int> coord2) {
  if (coord1.second < coord2.second)
    return true;
  if (coord1.second > coord2.second)
    return false;
  if (coord1.first > coord2.first)
    return true;
  return false;
}

int main() {
  ifstream cin("castle.in");
  ofstream cout("castle.out");

  // read in castle input somehow
  int m, n;
  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> castle[i][j];
      group[i][j] = NO_GROUP;
    }
  }

  int g = FIRST_GROUP;
  int max_size = 0;

  vector<int> groups;

  // use flood fill
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (group[i][j] != NO_GROUP)
        continue;

      int cur_size = 0;
      vector<pair<int, int>> visiting;
      visiting.push_back({i, j});
      group[i][j] = g;

      while (!visiting.empty()) {
        pair<int, int> coords = visiting.back();
        int y = coords.first, x = coords.second;
        visiting.pop_back();

        // check dirs
        for (int k = 0; k < 4; k++)
          if (!((castle[y][x] >> k) & 1) &&
              group[y + dirs[k].first][x + dirs[k].second] == NO_GROUP) {

            group[y + dirs[k].first][x + dirs[k].second] = g;
            visiting.push_back({y + dirs[k].first, x + dirs[k].second});
          }

        cur_size++;
      }
      groups.push_back(cur_size);
      max_size = max(cur_size, max_size);
      g++;
    }
  }

  // num rooms
  cout << g - FIRST_GROUP << endl;
  // max_size
  cout << max_size << endl;

  // then for each pair of rooms, find wall that can be removed + size of new
  //    room

  int max_two = 0;
  pair<int, int> coord;
  char dir;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 4; k++) {
        int newi = i + dirs[k].first, newj = j + dirs[k].second;
        if (newi < 0 || newj < 0 || newi >= n || newj >= m)
          continue;
        if ((castle[i][j] >> k) & 1 && group[newi][newj] != group[i][j]) {
          int s1 = groups[group[i][j] - 1];
          int s2 = groups[group[newi][newj] - 1];
          pair<int, int> newcoord = {max(i, newi), min(j, newj)};
          if ((s1 + s2 == max_two && better_place(newcoord, coord)) ||
              s1 + s2 > max_two) {
            max_two = s1 + s2;
            coord = newcoord;
            if (dirs[k].first == 0) {
              dir = 'E';
            } else {
              dir = 'N';
            }
          }
        }
      }
    }
  }

  cout << max_two << endl;
  cout << coord.first + 1 << " " << coord.second + 1 << " " << dir << endl;
}
