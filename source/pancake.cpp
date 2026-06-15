#include <bits/stdc++.h>
using namespace std;
vector<int> V;
int ix = 0;

int factorial(int n){
    int ans = 1;
    for(int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}

void pp(int k, int n){
    if(!V.empty()) V.pop_back();
    V.emplace_back(k);
    vector<int> V1;
    int kk = factorial(k - 1);
    for(int i = 0; i < k; i++)
        for(int j = 0; j < kk; j++)
            V1.emplace_back(V[j]);
    V = V1;
    if(k < n) pp(k + 1, n);
}

void prepara(int N) {
    pp(2, N);
    return;
}

int ribalta() {
    return V[ix++];
}