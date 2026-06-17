#include<bits/stdc++.h>
using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  string S; cin >> S;
  vector<pair<int, int>> rank(N);
  vector<int> ans(N);
  int r = 0;
  for(int i = 0; i < N - 1; i++){
    if(S[i] == '<'){
      r++;
    } else r--;
    rank[i + 1] = {r, i + 1};
  }
  sort(begin(rank), end(rank));
  for(int i = N - 1; i > -1; i--)
    ans[rank[i].second] = i + 1;
  for(int i = 0; i < N; i++)
    cout << ans[i] << " ";
}
