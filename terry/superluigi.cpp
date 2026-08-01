#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int TT;
    cin >> TT;
    for (int test = 1; test <= TT; ++test) {
        int N, M;
        cin >> N >> M;
        vector<int> H(N);
        for (int i = 0; i < N; ++i)
            cin >> H[i];
        vector<int> D(N);
        for (int i = 0; i < N; ++i)
            cin >> D[i];

        vector<vector<int>> T(2, vector<int> (M));
        vector<vector<int>> h(N, vector<int> (M));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                h[i][j] = H[i] + D[i] * j;
        for(int j = 0; j < M; j++)
            T[0][j] = h[0][j];

        function <pair<int, int>(int, int)> find;
        find = [&] (int i, int j) -> pair<int, int> {
            int hh = h[i][j];
            if(hh > h[i - 1][M - 1]) return {M - 1, M - 1};
            int h1 = lower_bound(begin(h[i - 1]), end(h[i - 1]), hh) - h[i - 1].begin();
            if(h[i - 1][h1] == hh) return {h1, h1};
            if(h1 == 0) return {0, 0};
            return {h1, h1 - 1};
        };

        for(int i = 1; i < N; i++){
            T[1].assign(M, 1e9);
            for(int j = 0; j < M; j++) {
                auto [a, b] = find(i, j);
                int hh = h[i][j];
                T[1][j] = min(T[1][j], min(T[0][a] + abs(h[i - 1][a] - hh), T[0][b] + abs(h[i - 1][b] - hh)));
            }
            T[0] = T[1];
        }

        int tempo = 1e9;
        for(auto u: T[0])
            tempo = min(tempo, u);
        cout << "Case #" << test << ": ";
        cout << tempo << endl;
    }

    return 0;
}