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
#define FR(i, a, b) for (ll i = (b) - 1; i >= (a); --i)

const int MAX_N = 305;
const ll INF = 1e15;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};

int n;
double dp[MAX_N][MAX_N][MAX_N];

double go(int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0)
    return 0;
  if (a == 0 && b == 0 && c == 0)
    return 0;
  if (dp[a][b][c] > 0)
    return dp[a][b][c];
  return dp[a][b][c] =
             double(n + a * go(a - 1, b, c) + b * go(a + 1, b - 1, c) +
                    c * go(a, b + 1, c - 1)) /
             double(a + b + c);
}

inline void solve() {
  cin >> n;
  vi cnt(4, 0);
  FI(i, 0, n) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  cout << fixed << setprecision(10) << go(cnt[1], cnt[2], cnt[3]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
