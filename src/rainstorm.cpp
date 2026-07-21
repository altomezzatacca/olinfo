#include "bits/stdc++.h"
using namespace std;

struct dsu{
    int cc;
    vector<int> parent, sz;
    dsu(int n){
        cc = n;
        parent.resize(n);
        sz.resize(n);
        fill(begin(sz), end(sz), 1);
        iota(begin(parent), end(parent), 0);
    }
    int find(int a){
        if (a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        cc--;
    }
};

int main(){
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M), R(M);
    for(int i = 0; i < M; i++)
        cin >> A[i] >> B[i] >> R[i];
    int l = 0, r = 1e6 + 1;
    while(r - l > 1){
        int m = (l + r) >> 1;
        dsu d = dsu(N);
        for(int i = 0; i < M; i++)
            if(R[i] >= m)
                d.unite(A[i], B[i]);
        d.cc == 1 ? l = m : r = m;
    }
    cout << l << "\n";
}