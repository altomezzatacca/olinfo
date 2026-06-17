#include <bits/stdc++.h>
using namespace std;

enum event{
  arrivo,
  uscita
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long N, M; cin >> N >> M;
  vector<long long> R(N), W(M);
  queue<tuple<long long, event>> pq;
  iota(begin(R), end(R), 1);
  set<long long> free(begin(R), end(R));
  queue<long long> waiting;
  map<long long, long long> m;
  for(auto &u: R)
    cin >> u;
  for(auto &u: W)
    cin >> u;
  for(int i = 0; i < 2 * M; i++){
    long long x; cin >> x;
    event e = (x > 0 ? arrivo : uscita);
    pq.emplace(abs(x), e);
  }
  long long ans = 0;
  while(!pq.empty()){
    auto[i, e] = pq.front(); pq.pop();
    if(e == 0){
      if(free.empty()){
        waiting.emplace(i);
      }
      else{
        auto it = free.begin();
        ans += W[i - 1] * R[*it - 1];
        m[i] = *it;
        free.erase(it);
      }
    } else {
      free.insert(m[i]);
      if(!waiting.empty()){
        auto it = free.begin();
        auto q = waiting.front(); waiting.pop();
        ans += W[q - 1] * R[*it - 1];
        m[q] = *it;
        free.erase(it);
      }
    }
  }
  cout << ans << "\n";
}