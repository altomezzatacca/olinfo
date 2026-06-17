#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, L, K; cin >> N >> M >> L >> K;
  if ((L % 3 != 0 && K != 0) || K > (N - L + 1) * (M - L + 1)) {cout << "NO"; return 0; }
  vector<vector<char>> V (N, vector<char> (M));
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      V[i][j] = ((i + j) % 2 ? 'B' : 'B');
  int c = 0;
  if (K == 0) {
  } else if (K == 1){
    for(int i = 0; i < L; i++)
      for(int j = 0; j < L; j++, c++, c %= 3){
        if(c == 0) V[i][j] = 'R';
        if(c == 1) V[i][j] = 'G';
        if(c == 2) V[i][j] = 'B';
      }
  } else if (N == 3){
    for(int i = 0; i < K + L - 1; i++){
      V[0][i] = 'R';
      V[1][i] = 'G';
      V[2][i] = 'B';
    }
  } else {
    int maxq = M - L + 1;
    int rows = K / maxq;
    int rem = K % maxq;
    for(int j = 0; j < M; j++, c++, c %= 3){
        if(c == 0) V[0][j] = 'R';
        if(c == 1) V[0][j] = 'G';
        if(c == 2) V[0][j] = 'B';
    }
    for(int i = 1; i < L - 1; i++)
      for(int j = 0; j < M; j++)
        V[i][j] = V[i - 1][j];
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < M; j++)
        V[i + L - 1][j] = V[i + L - 2][j];
    int ix = 0;
    while(V[ix][0] == 'R')
      ix++;
    for(int i = 0; i < rem + L - 2; i++)
      V[ix][i] = V[ix - 1][i];
    for(int i = rem + L - 2; rem != 0 && i < M; i++)
      V[ix][i] = V[ix][i - 1];
  }
  cout << "YES\n";
  for(int i = 0; i < N; i++, cout << "\n")
    for(int j = 0; j < M; j++)
      cout << V[i][j];
}