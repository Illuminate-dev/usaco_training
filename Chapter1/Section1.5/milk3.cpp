/*
PROG: milk3
LANG: C++
ID: henrydb1
*/

#include <fstream>
#include <iostream>

using namespace std;

struct State {
  int a[3];
};

State state(int a, int b, int c) {
  State s;
  s.a[0] = a;
  s.a[1] = b;
  s.a[2] = c;
  return s;
}

int cap[3];

State pour(State s, int from, int to) {
  int amt;

  amt = s.a[from];
  if (s.a[to] + amt > cap[to])
    amt = cap[to] - s.a[to];

  s.a[from] -= amt;
  s.a[to] += amt;
  return s;
}

bool visited[21][21][21];
bool ans[21];

void search(State s) {
  if (visited[s.a[0]][s.a[1]][s.a[2]]) {
    return;
  }

  visited[s.a[0]][s.a[1]][s.a[2]] = true;

  if (s.a[0] == 0) {
    ans[s.a[2]] = true;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        search(pour(s, i, j));
      }
    }
  }
}

int main() {
  ifstream cin("milk3.in");
  ofstream cout("milk3.out");

  cin >> cap[0] >> cap[1] >> cap[2];

  search(state(0, 0, cap[2]));

  bool first = true;
  for (int i = 0; i < 21; i++) {
    if (ans[i]) {
      if (!first) {
        cout << " ";
      }
      first = false;
      cout << i;
    }
  }

  cout << endl;
}
