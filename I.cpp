#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
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
#define FR(i, a, b) for (ll i = (b); i >= (a); --i)

const int MAX_N = 1e5 + 5;
const ll INF = 1e15;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};

inline void solve() {
  int N;
  cin >> N;
  vector<double> p(N);
  FI(i, 0, N) cin >> p[i];
  vector<double> dp(N + 1, 0);
  dp[0] = 1;
  FI(i, 0, N) FR(j, 0, i + 1) {
    if (!j)
      dp[j] = dp[j] * (1 - p[i]);
    else {
      dp[j] = dp[j] * (1 - p[i]) + dp[j - 1] * p[i];
    }
  }
  double ans = 0.0;
  FI(i, 0, N + 1) {
    if (i > N / 2)
      ans += dp[i];
  }
  cout << fixed << setprecision(10) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  t = 1;
  while (t--)
    solve();

  return 0;
}
