#include <bits/stdc++.h>
using namespace std;

int solve(){
  int N; cin >> N;
  vector<int> V(N);
  int ans = 0;
  for(auto &u: V) cin >> u;
  int _min, _max = -1;
  while(_max != 0){
    _max = -1;
    _min = 1001;
    for(int i = 0; i < N; i++){
      _max = max(_max, V[i]);
      _min = min(_min, (V[i] <= 0 ? _min : V[i]));
    }
    if(_min == 1001 || _max == 0) break;
    ans++;
    bool b = 0;
    for(int i = 0; i < N; i++){
      if(V[i] == 0){
        if(b) break;
      } else {
        b = 1;
        V[i]--;
      }
    }
  }
  return ans;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T; cin >> T;
  for(int t = 1; t <= T; t++)
    cout << "Case #" << t << ": " << solve() << "\n";
}