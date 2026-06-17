#include <bits/stdc++.h>
using namespace std;

int main() {
  set<string> s;
  int N; cin >> N;
  while(N--){
    string S; cin >> S;
    s.insert(S);
  }
  cout << s.size() + 1;
}