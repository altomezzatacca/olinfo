#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0, M = 0, B = 0;
  cin >> N;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(M >= 50) {ans++; M -= 50;}
    else if (B >= 80) {ans++; B -= 80;}
    int x; char y;
    cin >> x >> y;
    if(y == 'M') M += x;
    else B += x;
  }
  cout << ans << "\n";
}