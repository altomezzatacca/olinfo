#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int X, Y, Mx, My, N; cin >> X >> Y >> Mx >> My >> N;
    vector<pair<int, int>> P(N);
    vector<vector<int>> G(X + 1, vector<int>(Y + 1, -1));
    vector<int> visited(N + 1);
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y; G[x][y] = i;
        cin >> x >> y; P[i] = {x, y};
    }
    int turip = N, ans = 0;
    while(!visited[turip]){
        visited[turip] = 1;
        ans++;
        int d = X + Y + 1;
        for(int xx = 0; xx < X + 1; xx++)
            for(int yy = 0; yy < Y + 1; yy++)
                if((G[xx][yy] != -1) && (abs(Mx - xx) + abs(My - yy) < d)){
                    turip = G[xx][yy];
                    d = abs(Mx - xx) + abs(My - yy);
                }
        Mx = P[turip].first;
        My = P[turip].second;
    }
    cout << ans - 1 << "\n";  
    return 0;
}