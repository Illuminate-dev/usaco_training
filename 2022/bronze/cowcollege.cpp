#include <algorithm>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
  ll n;
  cin >> n;

  ll c[n];
  for (ll i = 0; i < n; i++)
    cin >> c[i];

  sort(c, c + n);

  ll max = 0;
  ll tuition = 0;
  for (ll i = 0; i < n; i++) {
    if (c[i] * (n - i) > max) {
      max = c[i] * (n - i);
      tuition = c[i];
    }
  }

  cout << max << " " << tuition << endl;
}
