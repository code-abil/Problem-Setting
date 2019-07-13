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
#endif-

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main() {
  int vertices;
  cin >> vertices;
  vector<pair<int, int>> edges;
  vector<int> done = {1}, rem;
  for (int i = 2; i <= vertices; ++i) {
    rem.emplace_back(i);
  }
  shuffle(rem.begin(), rem.end(), rng);
  int ctr = 0;
  while (ctr != (int) rem.size()) {
    int u = done[get_rand(0, done.size() - 1)];
    int v = rem[ctr++];
    edges.emplace_back(u, v);
    done.emplace_back(v);
  }
  cout << "Edges:\n";
  for (auto [u, v] : edges) {
    cout << u << " " << v << "\n";
  }
}
