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
  int n;
  cin >> n;
  vector<int> C(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> C[i];
  }
  sort(C.begin() + 1, C.end());
  int vasya = 0, petya = 0;
  for (int i = n, done = 0; i >= 1; --i, ++done) {
    if (done & 1) {
      vasya += C[i];
    } else {
      petya += C[i];
    }
  }
  if (vasya > petya) {
    cout << "Vasya\n";
  } else if (petya > vasya) {
    cout << "Petya\n";
  } else {
    cout << "Tie\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
