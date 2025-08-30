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

const int MAX_N = 405;
const ll INF = (ll)1e15;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};

int n;
ll a[MAX_N], pref[MAX_N];
ll dp[MAX_N][MAX_N];

ll solve_range(int i, int j) {
  if (i == j)
    return 0;
  ll &res = dp[i][j];
  if (res != -1)
    return res;
  res = INF;
  ll sum_ij = pref[j] - pref[i - 1];
  for (int k = i; k < j; k++) {
    res = min(res, solve_range(i, k) + solve_range(k + 1, j) + sum_ij);
  }
  return res;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << solve_range(1, n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  while (t--)
    solve();

  return 0;
}
