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

vector<int> adj[MAX_N];
vector<int> dist;
int N, M;

int dfs(int u) {
  if (dist[u] != -1) {
    return dist[u];
  }

  int longest = 0;
  for (auto v : adj[u]) {
    longest = max(longest, dfs(v));
  }

  return dist[u] = 1 + longest;
}

inline void solve() {
  cin >> N >> M;
  dist.assign(N + 1, -1);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  int res = 0;
  for (int i = 1; i <= N; i++) {
    res = max(res, dfs(i));
  }

  cout << res - 1 << endl;
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
