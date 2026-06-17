#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  int ans = 0;
  while(N--){
    int x; cin >> x;
    ans += max(0, x - 1);
  }
  cout << ans << endl;
  return 0;
}