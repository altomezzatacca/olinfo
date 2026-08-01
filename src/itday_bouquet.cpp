#include <bits/stdc++.h>
using namespace std;

int componi(int N, int J, vector<int> F) {
  sort(begin(F), end(F));
  vector<long long> mancanti(N);
  for(long long i = 1; i < N; i++)
    mancanti[i] = mancanti[i - 1] + i * (F[i] - F[i - 1]);
  long long l = 0, r = N;
  while(r - l > 1){
    long long m = (l + r) >> 1;
    if(mancanti[m] > J) r = m;
    else l = m;
  }
  long long ans = F[l] + (J - mancanti[l]) / (l + 1);
  return ans;
}