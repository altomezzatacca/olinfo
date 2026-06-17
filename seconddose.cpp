#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  map<int, int> m;
  for(int i = 0; i < N; i++){
    int x; cin >> x;
    m[x]++;
  }
  for(int i = 0; i < M; i++){
    int x; cin >> x;
    m[x]++;
  }
  int ans = 0;
  for(auto u: m) if(u.second == 2) ans++;
  cout << ans << "\n";
}