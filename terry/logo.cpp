#include <string>
#include <iostream>
#include <vector>
using namespace std;

void solve(int t){
    int N, M;
    cin >> N >> M;
    vector<string> logo_iniziale(N), logo_finale(N);
    for(auto &x: logo_iniziale)cin >> x;
    for(auto &x: logo_finale)cin >> x;
    int risposta = 42;
    int x_sx = M, x_dx = -1, y_up = N, y_dw = -1;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(logo_iniziale[i][j] != logo_finale[i][j]){
                x_sx = min(x_sx, j);
                x_dx = max(x_dx, j);
                y_up = min(y_up, i);
                y_dw = max(y_dw, i);
            }
    if(x_sx == M || x_dx == -1 || y_up == N || y_dw == -1) risposta = 0;
    else risposta = (x_dx - x_sx + 1) * (y_dw - y_up + 1);
    cout << "Case #" << t << ": " << risposta << "\n";
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
