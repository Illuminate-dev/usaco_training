#include <bits/stdc++.h>

using namespace std;

int N;
string cows;
int lists[100000];
int main() {
  cin >> N;
  cin >> cows;
  int last_H;
  int first_H = -1;
  int last_G;
  int first_G = -1;
  for (int i = 0; i < N; i++) {
    cin >> lists[i];
    if (cows[i] == 'G') {
      if (first_G == -1)
        first_G = i;
      last_G = i;
    } else {
      if (first_H == -1)
        first_H = i;
      last_H = i;
    }
  }

  int out = 0;

  // first H is leader
  if (lists[first_H] - 1 >= last_H) {
    for (int i = 0; i < first_H; i++) {
      if (lists[i] - 1 >= first_H)
        out++;
    }
  }

  if (lists[first_G] - 1 >= last_G) {
    for (int i = 0; i < first_G; i++) {
      if (lists[i] - 1 >= first_G)
        out++;
    }
  }

  if (lists[first_G] - 1 >= last_G && lists[first_H] - 1 >= last_H)
    out++;

  cout << out << endl;
}
