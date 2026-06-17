#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N, M, A;
  cin >> N >> M >> A;
  long long res = 0;
  for(long long i = 1; i * i <= A; i++){
    if(A % i == 0){
      long long j = A / i;
      if(i >= N && j >= M) res++;
      if(i >= M && j >= N && i != j) res++;
    }
  }
  cout << res << endl;
  return 0;
}