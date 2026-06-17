#include<bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> P(N);
  for(auto &u: P) cin >> u;
  long long ans = 0, last = 0;
  for(int i = 0; i < N; i++)
    if(P[i] > last){
      last = P[i];
      ans += last;
    }
  cout << ans << "\n";
}