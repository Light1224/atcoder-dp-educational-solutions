#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define ld long double

const ll INF = 1e18;

inline void solve() {
  int N;
  ll W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  for (int i = 0; i < N; i++)
    cin >> w[i] >> v[i];

  int MAXVAL = 0;
  for (int i = 0; i < N; i++)
    MAXVAL += v[i];

  vector<ll> dp(MAXVAL + 1, INF);
  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = MAXVAL; j >= v[i]; j--) {
      dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    }
  }

  ll ans = 0;
  for (int i = 0; i <= MAXVAL; i++) {
    if (dp[i] <= W)
      ans = i;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}
