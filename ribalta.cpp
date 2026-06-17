#include <bits/stdc++.h>
using namespace std;

int ribalta(int N, string S) {
  int u = 0;
  for(int i = 0; i < N; i++){
    if(S[i] == '1') 
      u++;
  }
  vector<pair<int, int>> V (N + 2, {0, u});
  for(int i = 0; i < N; i++){
    if(S[i] == '1'){
      V[i + 1] = V[i];
      V[i + 1].second--;
    } else {
      V[i + 1] = V[i];
      V[i + 1].first++;
    }
  }
  int best = u;
  for(int i = 0; i <= N; i++)
    best = max(best, V[i].first + V[i].second);
  return best;
}