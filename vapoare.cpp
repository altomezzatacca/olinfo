#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n, number;
    vector<int> parent;
    vector<int> sz;
    DSU(int N){
        n = N;
        number = n;
        parent.resize(N);
        sz.resize(N);
        for(int i = 0; i < N; i++){ 
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        while(x != parent[x]) x = parent[x];
        return x;
    }
    void unite(int a, int b){
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
    }
};

void traverse(int N, int K, int T, vector<int> &A, vector<int> &B, vector<int> &W, vector<int> &V) {
    vector<array<int, 3>> types(T); //valore, indice, risposta
    vector<array<int, 3>> edges(K); //W, A, B
    vector<int> ans(T);
    for(int i = 0; i < T; i++){
        types[i][0] = V[i];
        types[i][1] = i;
    }
    for(int i = 0; i < K; i++){
        edges[i] = {W[i], A[i] - 1, B[i] - 1}; //mannaggia all'1-index
    }
    sort(rbegin(types), rend(types)); //ordine decrescente
    sort(rbegin(edges), rend(edges)); //ordine decrescente
    int i = 0;
    DSU dsu(N);
    for(int t = 0; t < T; t++){
        auto &[width, ix, v] = types[t];
        while(i < K && edges[i][0] >= width){
            int a = dsu.find(edges[i][1]);
            int b = dsu.find(edges[i][2]);
            if(a != b){
                dsu.unite(a, b);
                dsu.number--;
            }
            i++;
        }
        ans[ix] = v = dsu.number;
    }
    for(int t = 0; t < T; t++) cout << ans[t] << "\n";
}


int main() {
    int N, K, T;
    cin >> N >> K >> T;
    vector<int> A(K), B(K), W(K);
    vector<int> V(T);    
    for(int i = 0; i < K; i++)
        cin >> A[i] >> B[i] >> W[i];
    for(int i = 0; i < T; i++)
        cin >> V[i];

    traverse(N, K, T, A, B, W, V);

    return 0;
}