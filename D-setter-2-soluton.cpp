#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> G(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<pair<int, int>> ranges(n + 1);
  vector<int> dep(n + 1);
  int timer = 0;
  function<void(int, int, int)> dfs = [&](int u, int p, int d) {
    ranges[u].first = ++timer;
    dep[u] = d;
    for (auto v : G[u]) {
      if (v != p) {
        dfs(v, u, d + 1);
      }
    }
    ranges[u].second = timer;
  };
  dfs(1, 0, 0);
  vector<pair<int, int>> info(n + 1);
  for (int i = 1; i <= n; ++i) {
    info[i] = {dep[i], ranges[i].first};
  }
  sort(info.begin() + 1, info.end());
  while (q--) {
    int c, d;
    cin >> c >> d;
    int tot_dep = dep[c] + d;
    int up = upper_bound(info.begin() + 1, info.end(), make_pair(tot_dep, ranges[c].second)) - info.begin();
    int lo = lower_bound(info.begin() + 1, info.end(), make_pair(tot_dep, ranges[c].first)) - info.begin();
    cout << up - lo << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
