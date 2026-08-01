#include <bits/stdc++.h>
using namespace std;

long long somma(int N){
  string s = to_string(N);
  int n = s.size();
  long long a = 0;
  for(int i = 0; i < n; i++)
    a += s[i] - '0';
  return a;
}

int main() {
  int d, N; cin >> d >> N; long long p = 1LL << (N - 1);
  long long ans = d * p; p>>=1;
  for(int i = 2; i <= N; i++){
    ans += somma(i) * p;
    p>>=1;
  }
  cout << ans;
}