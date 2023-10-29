#include <bits/stdc++.h>

using namespace std;

int N;
string S;

int main() {
  cin >> N;
  cin >> S;

  // divide into patterns of "BF...FB" or other
  int startidx = 0;

  int mn=0,mx=0;
  while (startidx < N) {
    if (S[startidx]=='F') {
      startidx++;
      continue;
    }

    int endidx = startidx+1;
    while (endidx < N && S[endidx]=='F') endidx++;

    if (endidx==N) {
      break;
    }

    int num_f = endidx-startidx-1;

    if (S[startidx]==S[endidx]) {
      if (num_f % 2 == 0) {
        mn += 1;
      }

      mx += num_f+1;

    } else {
      if (num_f % 2 != 0) {
        mn += 1;
      }

      mx += num_f;
    }

    startidx = endidx;
  }

  int num_starting = 0;
  while (num_starting < N && S[num_starting]=='F') num_starting++;
  int num_ending = 0;
  while (num_ending < N && S[N-1-num_ending]=='F') num_ending++;

  if (num_starting == N) {
    mn = 0;
    mx = N-1;
  } else {
    mx += num_starting + num_ending;
  }

  if (num_starting > 0 || num_ending > 0) {
    cout << (mx-mn+1) << endl;
    for (int i = mn; i <= mx; i++) cout << i << endl;
  } else {
    cout << ((mx-mn) / 2) + 1 << endl;
    for (int i = mn; i <= mx; i+=2) cout << i << endl;
  }


}
