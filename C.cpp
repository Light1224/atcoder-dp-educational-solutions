#include <algorithm>
#include <ios>
#include <iostream>
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
  int a[N], b[N], c[N];
  for (int i = 0; i < N; i++)
    cin >> a[i] >> b[i] >> c[i];
  int dp[N][3];
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  for (int i = 1; i < N; i++) {
    dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = c[i] + max(dp[i - 1][1], dp[i - 1][0]);
  }

  cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
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
