#include <bits/stdc++.h>
using namespace std;
vector<int> vx = {1, -1, 0, 0};
vector<int> vy = {0, 0, 1, -1};

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> H(N, vector<int>(M));
    for (int j = 0; j < N; ++j)
        for (int i = 0; i < M; ++i)
            cin >> H[j][i];
    vector<vector<pair<int, int>>> adj(N * M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < 4; k++){
                int x = i + vx[k];
                int y = j + vy[k];
                if(x >= 0 && x < N && y >= 0 && y < M)
                    adj[M * i + j].emplace_back(M * x + y, abs(H[i][j] - H[x][y]));
            }
    long long l = -1, r = 1e6; // l escluso, r incluso (:vomito:)
    while(r - l > 1){
        long long m = (l + r) >> 1;
        vector<int> used(N * M, K + 1);
        used[0] = 0;
        deque<pair<int, int>> pq;
        pq.emplace_front(0, 0);
        while(!pq.empty()){
            auto [k, u] = pq.front(); pq.pop_front();
            if(k > used[u]) continue;
            for(auto [v, w]: adj[u]){
                int cost = (w > m ? 1 : 0);
                if(used[v] > used[u] + cost)
                    if(cost == 0) pq.emplace_front(used[v] = used[u] + cost, v);
                    else if (cost == 1) pq.emplace_back(used[v] = used[u] + cost, v);
            }
        }
        if (used[N * M - 1] <= K) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}