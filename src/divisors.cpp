#include <bits/stdc++.h>
using namespace std;

long long compute(long long n) {
  long long ans = 0;
  for(long long k = 1; k <= n;){ // circa O(sqrt(n))
    long long v = n / k;
    long long r = n / v;
    ans += v * (r - k + 1);
    k = r + 1;
  }
  return ans;
}