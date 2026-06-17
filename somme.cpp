#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  vector<int> V(N);
  for(auto &u: V)
    cin >> u;
  long long ans = 0;
  priority_queue<long long, vector<long long>, greater<>> pq;
  for(int i = 0; i < N; i++) pq.emplace(V[i]);
  while((int)pq.size() > 1){
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    ans += x + y;
    pq.emplace(x + y);
  }
  cout << ans << "\n";
}