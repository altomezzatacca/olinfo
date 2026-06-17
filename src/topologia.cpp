#include <bits/stdc++.h>
using namespace std;

struct dsu{
    int n;
    vector<vector<int>> ccs;
    vector<int> parent;
    dsu (int N){
        n = N;
        parent.resize(N);
        for(int i = 0; i < n; i++)
            ccs.push_back({parent[i] = i});
    }
    int find (int x){
        while(x != parent[x]) x = parent[x];
        return x;
    }
    void unite (int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if((int)ccs[a].size() < (int)ccs[b].size()) swap(a, b);
        while((int)ccs[b].size() > 0){
            ccs[a].push_back({ccs[b].back()});
            ccs[b].pop_back();
        }
        parent[b] = a;
    }
};

void Analizza(int N, int M, int* A, int* B, int* T) {
    vector<int> degree(N);
    dsu ds(N);
    for(int i = 0; i < M; i++){
        A[i]--; B[i]--;
        degree[A[i]]++;
        degree[B[i]]++;
        ds.unite(A[i], B[i]);
    }
    for(vector<int> v: ds.ccs){
        int n = v.size();
        int deg1 = 0, deg2 = 0, degn = 0;
        for(auto u: v){
            if(degree[u] == 1) deg1++;
            if(degree[u] == 2) deg2++;
            if(degree[u] == n - 1) degn++;
        }
        if(n >= 2 && deg1 == 2 && deg2 == n - 2) T[0]++;
        if(n >= 3 && deg2 == n) T[1]++;
        if(n >= 4 && deg1 == n - 1 && degn == 1) T[2]++;
    }
}