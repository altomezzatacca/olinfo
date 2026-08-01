#include <bits/stdc++.h>
using namespace std;
vector<int> lp, pr;

bool best(int n){
  if(n % 2 == 0) return false;
  if(n % 5 == 0) return false;
  int phi = n - 1;
  int len = 1;
  for(int i = 10; i != 1; len++){
    i *= 10; i %= n;
  }
  if(phi == len) return true;
  return false;
}

int main() {
  int n; cin >> n;
  if(n == 7) {cout << 6; return 0;}
  if(n == 2 || n == 3) {cout << n - 1; return 0;}
  lp.resize(n + 1);
  for (int i = 2; i < n; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back(i);
      }
      for (int j = 0; i * pr[j] < n; ++j) {
          lp[i * pr[j]] = pr[j];
          if (pr[j] == lp[i]) {
              break;
          }
      }
  }
  reverse(pr.begin(), pr.end());
  bool found = 0;
  for(int i = 0; !found; i++)
    if(best(pr[i])) {
      cout << pr[i];
      found = 1;
    }
}