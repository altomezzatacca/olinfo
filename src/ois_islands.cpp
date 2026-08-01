#include "bits/stdc++.h"
using namespace std;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int main(){
    int R, C; cin >> R >> C;
    vector<vector<int>> M(R, vector<int> (C));
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> M[i][j];
    vector<vector<bool>> visited(R, vector<bool> (C));
    auto exists = [&] (int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < R && y < C);
    };
    function<void(int, int)> bfs = [&] (int x, int y) -> void {
        if(!exists(x, y)) return;
        if(M[x][y] == 0) return;
        if(visited[x][y]) return;
        visited[x][y] = 1;
        for(int k = 0; k < 4; k++)
            bfs(x + dx[k], y + dy[k]);
    };
    int ans = 0;
    for(int i = 0; i < R; i++){
        bfs(i, 0);
        bfs(i, C - 1);
    }
    for(int j = 0; j < C; j++){
        bfs(0, j);
        bfs(R - 1, j);
    }
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            if(visited[i][j] || M[i][j] == 0) continue;
            ans++;
            bfs(i, j);
        }
    cout << ans << "\n";
}
