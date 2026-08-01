#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int cnt = 0;
  while(N--){
    string S; cin >> S;
    if(!(S[1] == '3' && S[2] == '9')) continue;
    if(S.size() == 12 || S.size() == 13) cnt++;
  }
  cout << cnt;
}