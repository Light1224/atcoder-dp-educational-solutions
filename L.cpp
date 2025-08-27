#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<ll>>;

template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K> using uset = unordered_set<K>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

#define FI(i, a, b) for (ll i = (a); i < (b); ++i)
#define FR(i, a, b) for (ll i = (b) - 1; i >= (a); --i)

const int MAX_N = 1e5 + 5;
const ll INF = 1e15;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};

inline void solve() {
  ll n;
  cin >> n;
  vll a(n);
  FI(i, 0, n) cin >> a[i];

  vvl dp(n, vll(n, 0));

  FI(i, 0, n) dp[i][i] = a[i];

  for (ll len = 2; len <= n; ++len) {
    for (ll l = 0; l + len - 1 < n; ++l) {
      ll r = l + len - 1;

      ll pickLeft = a[l];
      if (l + 2 <= r)
        pickLeft += min(dp[l + 2][r], dp[l + 1][r - 1]);
      else if (l + 1 <= r)
        pickLeft += dp[l + 1][r - 1];

      ll pickRight = a[r];
      if (l <= r - 2)
        pickRight += min(dp[l][r - 2], dp[l + 1][r - 1]);
      else if (l <= r - 1)
        pickRight += dp[l + 1][r - 1];

      dp[l][r] = max(pickLeft, pickRight);
    }
  }

  ll firstPlayer = dp[0][n - 1];
  ll total = 0;
  for (ll val : a)
    total += val;

  ll secondPlayer = total - firstPlayer;
  cout << (firstPlayer - secondPlayer) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  while (t--)
    solve();
  return 0;
}
