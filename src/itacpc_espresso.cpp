#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  map<string, int> m;
  m["espresso"] = 1;
  m["espresso-doppio"] = 2;
  m["cappuccino"] = 1;
  m["affogato"] = 2;
  m["dead-eye"] = 3;
  m["irish-coffee"] = 2;
  int ans = 0;
  for(int i = 0; i < N; i++){
    string s; cin >> s;
    ans += m[s];
  }
  ans++; ans >>= 1;
  cout << ans;
}