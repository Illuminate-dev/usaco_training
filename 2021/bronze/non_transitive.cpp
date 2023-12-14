#include <bits/stdc++.h>

using namespace std;

struct Die {
  int sides[4];
};

bool die_beats_die(Die A, Die B) {
  int wins = 0;
  int losses = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (A.sides[i] < B.sides[j]) {
        losses++;
      }
      if (A.sides[i] > B.sides[j]) {
        wins++;
      }
    }
  }
  return wins > losses;
}

int run() {
  Die A, B;

  for (int i = 0; i < 4; i++) {
    cin >> A.sides[i];
  }

  for (int i = 0; i < 4; i++) {
    cin >> B.sides[i];
  }

  // Die C;
  // C.sides[0] = 1;
  // C.sides[1] = 4;
  // C.sides[2] = 8;
  // C.sides[3] = 9;
  // cout << die_beats_die(A, B) << endl;
  // cout << die_beats_die(B, C) << endl;
  // cout << die_beats_die(C, A) << endl;
  //

  Die C;
  for (C.sides[0] = 1; C.sides[0] <= 10; C.sides[0]++) {
    for (C.sides[1] = 1; C.sides[1] <= 10; C.sides[1]++) {
      for (C.sides[2] = 1; C.sides[2] <= 10; C.sides[2]++) {
        for (C.sides[3] = 1; C.sides[3] <= 10; C.sides[3]++) {
          // cout << C.sides[0] << " " << C.sides[1] << " " << C.sides[2] << " "
          //      << C.sides[3] << endl;
          if ((die_beats_die(A, B) && die_beats_die(B, C) &&
               die_beats_die(C, A)) ||
              (die_beats_die(B, A) && die_beats_die(A, C) &&
               die_beats_die(C, B))) {
            // cout << C.sides[0] << " " << C.sides[1] << " " << C.sides[2] << "
            // "
            //      << C.sides[3] << endl;
            cout << "yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "no" << endl;
  return 0;
}

int run_tests() {
  int T;
  cin >> T;
  while (T--) {
    run();
  }
  return 0;
}

int main() {

  // Die A, B, C;
  // A.sides[0] = 1;
  // A.sides[1] = 10;
  // A.sides[2] = 10;
  // A.sides[3] = 7;
  // B.sides[0] = 5;
  // B.sides[1] = 10;
  // B.sides[2] = 6;
  // B.sides[3] = 5;
  // C.sides[0] = 1;
  // C.sides[1] = 1;
  // C.sides[2] = 1;
  // C.sides[3] = 6;

  // cout << die_beats_die(A, B) << endl;
  run_tests();
}
