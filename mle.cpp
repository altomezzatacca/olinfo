#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &lnk){
    if(lnk[x] == x) return x;
    return lnk[x] = find(lnk[x], lnk);
}

void Colora(int N, int Q, vector <int> &A, vector <int> &B, vector <int> &C, vector <int> &murale){
    vector<int> lnk(N + 1); //punta al primo elemento libero >=
    for(int i = 0; i <= N; i++) lnk[i] = i;
    for(int i = Q - 1; i >= 0; i--){
        int ix = find(A[i], lnk);
        while(ix <= B[i]){
            murale[ix] = C[i];
            lnk[ix] = find(ix + 1, lnk);
            ix = find(ix, lnk);
        }
    }
}