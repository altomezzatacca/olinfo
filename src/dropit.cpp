#include <bits/stdc++.h>
using namespace std;

void cadi(vector<int> &V, int current, int c){
  if(V.empty()){
    V.emplace_back(current);
    return;
  }
  switch (c) {
    case 1:{ // current = V.back()
      V.pop_back();
      break;
    }
    case 2:{ // current < V.back()
      int x = V.back();
      V.emplace_back(current);
      V.emplace_back(x - current);
      break;
    }
    case 3:{ // current > V.back()
      current -= V.back();
      V.pop_back();
      if(current == V.back())
        cadi(V, current, 1);
      else if(current < V.back())
        cadi(V, current, 2);
      else
        cadi(V, current, 3);
      break;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  vector<int> L(N), ans;
  for(auto &u: L)
    cin >> u;
  for(int i = 0; i < N; i++){
    if(ans.empty()){
      ans.emplace_back(L[i]);
      continue;
    }
    int current = L[i];
    if(current == ans.back())
      cadi(ans, current, 1);
    else if(current < ans.back())
      cadi(ans, current, 2);
    else
      cadi(ans, current, 3);
  }
  cout << (int)ans.size() << "\n";
  for(auto u: ans)
    cout << u << " ";
  cout << "\n";
}