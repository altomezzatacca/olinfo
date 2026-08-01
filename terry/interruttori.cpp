#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> Z(A);
    vector<vector<int>> adj(N);
    
    for (int i = 0; i < A; i++) {
        cin >> Z[i];
    }

    for (int i = 0; i < B; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int> q;
    vector<int> dist(N, N + 1);
    
    for (int x: Z){
    	dist[x]=1;
    	q.push(x);
	}
	
	while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int u : adj[s]) {
            if (dist[u] > dist[s] + 1) {
                dist[u] = dist[s] + 1;
                q.push(u);
            }
        }
    }
    
    int idx = -1; // memorizza qui l'indice della lampadina
    int num = -1; // memorizza qui il numero di interruttori

    for(int i=0; i<N; i++){
        if (dist[i]>num && dist[i]!=N+1){
            idx=i;
            num=dist[i];
        }
    }
    
    cout << "Case #" << t << ": " << idx << " " << num << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
} 