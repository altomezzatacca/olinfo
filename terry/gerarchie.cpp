#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N; cin >> N;
    int risposta = 0;
    vector<array<int, 3>> V(N);
    vector<int> parent(N);
    for(int i = 0; i < N; V[i][2] = i, parent[i] = V[i][1], i++)
        cin >> V[i][1] >> V[i][0];
    sort(rbegin(V), rend(V));
    map<int, int> ix_to_i;
    for(int i = 0; i < N; i++)
        ix_to_i[V[i][2]] = i;
    vector<set<int>> adj(N);
    for(int i = 0; i < N; i++)
        if(parent[i] != -1)
            adj[parent[i]].insert(i);
    for(int j = 0; j < N; j++){
        int i = j;
        while((V[i][1] = parent[V[i][2]]) != -1 && V[i][0] > V[ ix_to_i[(V[i][1] = parent[V[i][2]])] ][0]){
            int p = ix_to_i[V[i][1]];
            int &c1 = V[i][0], &p1 = V[i][1] = parent[V[i][2]], &ix1 = V[i][2];
            int &c2 = V[p][0], &p2 = V[p][1] = parent[V[p][2]], &ix2 = V[p][2];
            //scambio i due nodi semplicemente cambiandogli il parent
            for(auto u: adj[ix1])
                parent[u] = ix2;
            for(auto u: adj[ix2])
                parent[u] = ix1;
            swap(adj[ix1], adj[ix2]);
            if(p2 != -1) adj[p2].erase(ix2);
            if(p2 != -1) adj[p2].insert(ix1);
            adj[ix1].insert(ix2);
            adj[ix1].erase(ix1);
            parent[ix1] = p1 = p2;
            parent[ix2] = p2 = ix1;
            risposta++;
        }
    }
    return risposta;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) 
        cout << "Case #" << t << ": " << solve() << endl;
}
