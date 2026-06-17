#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  int S; cin >> S;
  vector<int> H(N);
  for(int i = 0; i < N; i++)
    cin >> H[i];
  vector<vector<bool>> dpL(N + 1, vector<bool>(S + 1, 0));
  dpL[0][0] = 1;
  for(int i = 0; i < N; i++){
    dpL[i + 1] = dpL[i];
    for(int x = S - H[i]; x >= 0; x--)
      if(dpL[i][x]) dpL[i + 1][x + H[i]] = 1;
  }
  vector<vector<bool>> dpR(N + 1, vector<bool>(S + 1, 0));
  dpR[N][0] = 1;
  for(int i = N - 1; i >= 0; i--){
    dpR[i] = dpR[i + 1];
    for(int x = S - H[i]; x >= 0; x--)
      if(dpR[i + 1][x]) dpR[i][x + H[i]] = 1;
  }
  for(int i = 0; i < N; i++){
    bool b = 1;
    for(int j = 0; j <= S && b; j++)
      if(dpL[i][j] && dpR[i + 1][S - j])
        b = 0;
    cout << (b ? "YES\n" : "NO\n");
  }
  return 0;
}