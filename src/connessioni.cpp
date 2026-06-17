#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> parent, sz;

int find(int n){
    while (n != parent[n]) n = parent[n];
    return n;
}
void unite(int a, int b){
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    parent[b] = find(a);
    n--;
}

void inizia(int N) {
    n = N;
    parent.resize(N);
    sz.resize(N);
    iota(begin(parent), end(parent), 0);
    for(auto &u: sz) u = 1;
}

int collega(int X, int Y) {
    int x = find(X), y = find(Y);
    if(x != y)
        unite(x, y);
    return n;
}