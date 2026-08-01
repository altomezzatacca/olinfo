#include <bits/stdc++.h>
using namespace std;

int main() {
  long long L, N;
  cin >> L >> N;
  L += 12LL * (N / 6);
  N %= 6;
  vector<int> V = {1, 2, 3, 2, 1, 3};
  while(N--) L += V[N];
  cout << L;
}