/*
PROG: skidesign
ID: henrydb1
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
  ifstream in("skidesign.in");
  ofstream out("skidesign.out");
  
  int n, arr[1000];
  in >> n;
  
  for (int i = 0; i < n; i++) {
    in >> arr[i];
  }
    
  int ans = INT_MAX;
    
  for (int i = 0; i < 94;i++) {
    int curans = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j] < i)
        curans += pow(i-arr[j], 2);
      else if (arr[j] > i+17)
        curans += pow(arr[j]-(i+17), 2);
    }
    ans = min(curans, ans);
  }
  out << ans << endl;
}
