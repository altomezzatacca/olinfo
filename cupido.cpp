#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<pair<int, int>> V;
  int ans = 0;
  for(int i = 0; i < N; i++){
    int id, a, b, c; cin >> id >> a >> b >> c;
    if(a != -1) V.emplace_back(min(id, a), max(id, a));
    if(b != -1) V.emplace_back(min(id, b), max(id, b));
    if(c != -1) V.emplace_back(min(id, c), max(id, c));
  }
  sort(begin(V), end(V));
  for(int i = 0; i < (int)V.size() - 1; i++)
    if(V[i] == V[i + 1]) ans++;

  cout << ans << "\n";
  return 0;
}