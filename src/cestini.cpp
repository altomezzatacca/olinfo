#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> V;

void inizia(int N, int M) {
    V.resize(M);
    for(int i = 0; i < N; i++)
        V[0].push_back(i);
}

void sposta(int a, int b) {
    int x = V[a].back();
    V[a].pop_back();
    V[b].push_back(x);
}

int controlla(int a, int i) {
    if(V[a].size() < i + 1) return -1;
    return V[a][i];
}