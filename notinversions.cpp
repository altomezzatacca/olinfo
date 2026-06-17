#include <bits/stdc++.h>
using namespace std;
constexpr static int mod = 1e9 + 7;

int fast_exp (long long b, int e){
  long long ans = 1;
  while(e){
    if(e & 1)
      ans = (ans * b) % mod;
    e >>= 1;
    b = (b * b) % mod;
  }
  return ans;
}

int factorial (int n){
  long long ans = 1;
  for(int i = 2; i <= n; i++)
    ans = (ans * i) % mod;
  return (int)ans;
}

int catalan (int n){
  long long ans = 1;
  long long a = 2 * n + 1;
  a = fast_exp(a, mod - 2); // inverso moltiplicativo di 2n + 1
  long long b = factorial(2 * n + 1);
  long long c = factorial(n);
  c = fast_exp(c, mod - 2);
  long long d = factorial(n + 1);
  d = fast_exp(d, mod - 2);
  ans = (ans * a) % mod;
  ans = (ans * b) % mod;
  ans = (ans * c) % mod;
  ans = (ans * d) % mod;
  return ans;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int N;
    cin >> N;
    int S = 0;

    S = factorial(N) - catalan(N);
    if(S < 0) S += mod;

    cout << S << endl;
    return 0;
}