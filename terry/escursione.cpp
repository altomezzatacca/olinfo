#include <bits/stdc++.h>
using namespace std;
vector<int> vx = {1, -1, 0, 0};
vector<int> vy = {0, 0, 1, -1};

int solve(){
    int H, W; cin >> H >> W;
    int A[H][W];
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            cin >> A[i][j];
    vector<vector<pair<int, int>>> adj(H * W);
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            for(int k = 0; k < 4; k++){
                int x = i + vx[k];
                int y = j + vy[k];
                if(x >= 0 && x < H && y >= 0 && y < W)
                    adj[W * i + j].emplace_back(W * x + y, abs(A[i][j] - A[x][y]));
            }
    vector<int> dp(H * W, 1e9);
    dp[0] = 0;
    for(int k = 0; k < H * W; k++)
        for(int i = 0; i < H * W; i++)
            for(auto [u, w]: adj[i])
                dp[u] = min(dp[u], max(dp[i], w));
    return dp[H * W - 1];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
        cout << "Case " << t << ": " << solve() << endl;
}