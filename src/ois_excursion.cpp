#include "bits/stdc++.h"
using namespace std;
vector<int> vx = {0, 0, 1, -1};
vector<int> vy = {1, -1, 0, 0};
constexpr static int inf = 1e9;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> v(H, vector<int> (W));
    for(int i = 0; i < H; i++)
        for(auto &u: v[i])
            cin >> u;
    int x = 0, y = 0, lx = -1, ly = -1;
    int len = 0;
    vector<vector<int>> visited(H, vector<int> (W, -1));
    visited[0][0] = 0;
    auto get_next = [&] (int x, int y, int lx, int ly) -> pair<int, int> {
        int min_delta = inf;
        int xx = x, yy = y;
        for(int k = 0; k < 4; k++){
            int nx = x + vx[k], ny = y + vy[k];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(nx == lx && ny == ly) continue;
            int delta = abs(v[x][y] - v[nx][ny]);
            if(delta < min_delta){
                min_delta = delta;
                xx = nx;
                yy = ny;
            }
            if(delta == min_delta && v[x][y] > v[nx][ny]){
                min_delta = delta;
                xx = nx;
                yy = ny;
            }
        }
        return {xx, yy};
    };
    int b = 1;
    while(b){
        auto [nx, ny] = get_next(x, y, lx, ly);
        if(visited[nx][ny] == -1){
            visited[nx][ny] = visited[x][y] + 1;
            len++;
            lx = x, ly = y;
            x = nx, y = ny;
        } else {
            b = 0;
            len += visited[nx][ny] + 1;
        }
    }
    cout << len << "\n";
}
