#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <sys/types.h>
#include <vector>
using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld ESP = 1e-9;

inline void solve() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<int> dp(N, 0);
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);

  for (int i = 2; i < N; i++) {
    dp[i] =
        min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
  }

  cout << dp[N - 1] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
