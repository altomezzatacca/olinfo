#include <bits/stdc++.h>
using namespace std;

int sfangate(int N, vector<int> &V){
  int ans = 0, val = 0;
  vector<int> us;
  for(int i = 0; i < N; i++){
    val += V[i];
    if(V[i] < 0) us.push_back(V[i]);
  }
  sort(us.begin(), us.end());
  while(val <= 0)
    val -= 2 * us[ans++];
  return ans;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  vector<int> V(N);
  for(int i = 0; i < N; i++)
    cin >> V[i];
  cout << sfangate(N, V);
}