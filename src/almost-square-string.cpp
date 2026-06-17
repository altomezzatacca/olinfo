#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  unordered_map<int, int> M;
  while(N--){
    char c; cin >> c;
    M[c - 'a']++;
  }
  for(auto u: M)
    if(u.second % 2 == 1){
      char c = 'a' + u.first;
      cout << c;
      break;
    }
}