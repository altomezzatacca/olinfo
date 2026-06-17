#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
using namespace std;
map<vector<int>, int> cnt[5]; // 5 perchè per ogni n da 0 (2) a 4

void gen(int &n, int &m, int current, vector<int> &scores, vector<pair<int, int>> &matches){
    if(m == current){
        cnt[n][scores]++;
        return;
    }
    auto [a, b] = matches[current];
    scores[a] += 100; scores[b] += 1;
    gen(n, m, current + 1, scores, matches);
    scores[a] -= 100; scores[b] -= 1;
    scores[a] += 10; scores[b] += 10;
    gen(n, m, current + 1, scores, matches);
    scores[a] -= 10; scores[b] -= 10;
    scores[a] += 1; scores[b] += 100;
    gen(n, m, current + 1, scores, matches);
    scores[a] -= 1; scores[b] -= 100;
}

inline void precompute(){
    for(int n = 2; n <= 4; n++){
        int m = n * (n - 1);
        vector<pair<int, int>> matches;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j) matches.emplace_back(i, j);
        vector<int> scores(n, 0);
        gen(n, m, 0, scores, matches);
    }
}

bool isSorted(vector<int> V){
    for(int i = 0; i < (int)V.size() - 1; i++){
        int Aw = V[i] / 100, Ad = (V[i] / 10) % 10, Ap =  3 * Aw + Ad;
        int Bw = V[i + 1] / 100, Bd = (V[i + 1] / 10) % 10, Bp =  3 * Bw + Bd;
        if(Ap < Bp) return 0;
        else if (Ap == Bp && Aw < Bw) return 0;
    }
    return 1;
}

inline string solve(){
    int N; cin >> N;
    vector<int> V(N);
    for(auto &u: V) 
        cin >> u;
    if(!isSorted(V)) return "Invalid";
    if(cnt[N][V] == 0) return "Invalid";
    if(cnt[N][V] == 1) return "Unique";
    return "Not unique";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T; cin >> T;
    for (int t = 0; t < T; t++)
        cout << solve() << "\n";
    return 0;
}