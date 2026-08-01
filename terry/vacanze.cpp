#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;

void solve(int t) {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    vector<set<int>> adj(N);
    for (int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        adj[A[i]].insert(B[i]);
        adj[B[i]].insert(A[i]);
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            int a = A[i], b = B[i];
            int c = A[j], d = B[j];
            if(a == c || a == d || b == c || b == d) continue;
            if(adj[a].count(c) && adj[b].count(d) && !adj[a].count(d) && !adj[b].count(c)) ans++;
            if(adj[b].count(c) && adj[a].count(d) && !adj[b].count(d) && !adj[a].count(c)) ans++;
        }
    }
    cout << "Case #" << t << ": " << (ans >> 2) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
    return 0;
}