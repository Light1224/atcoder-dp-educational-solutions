#include <ios>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld ESP = 1e-9;

inline void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<int> dp(N + 1);
  dp[0] = 0;

  for (int i = 1; i < N; i++) {
    dp[i] = INF;
    for (int j = 1; j <= K; j++) {
      if (i >= j) {
        dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
      }
    }
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
