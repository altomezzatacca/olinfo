#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  bool bal = 1;
  //vediamolo come un grafo: se a > b esiste un arco che va da a a b
  vector<pair<set<int>, set<int>>> adj (26);
  for(int i = 0; bal && (i < N); i++) {
    char a, sign, b; cin >> a >> sign >> b;
    int A = a - 'a', B = b - 'a';
    if(sign == '>'){
      adj[A].first.insert(B);
      adj[B].second.insert(A);
      for(auto u: adj[B].first) {
        adj[A].first.insert(u);
        adj[u].second.insert(A);
      }
    } else {
      adj[B].first.insert(A);
      adj[A].second.insert(B);
      for(auto u: adj[A].first) {
        adj[B].first.insert(u);
        adj[u].second.insert(B);
      }
    }
  }
  for(int j = 0; (j < 26) && bal; j++){
    for(int i = 0; (i < 26) && bal; i++){
      if(adj[j].first.count(i) == 1 && adj[j].second.count(i) == 1) bal = 0;
    }
  }
  cout << (bal ? ":)" : ":(");
}