#include <algorithm>
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
  string S, T;
  cin >> S >> T;
  int n = S.size();
  int m = T.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (S[i - 1] == T[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  string res;
  int i = n, j = m;
  while (i && j) {
    if (S[i - 1] == T[j - 1]) {
      res += S[i - 1];
      i--;
      j--;
    } else if (dp[i][j - 1] >= dp[i - 1][j])
      j--;
    else
      i--;
  }

  reverse(res.begin(), res.end());
  cout << res << endl;
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
