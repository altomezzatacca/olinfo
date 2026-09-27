#include "bits/stdc++.h"
using namespace std;
using ll = long long;

pair<vector<int>, vector<int>> disegna(int N, long long C, long long D) {
    vector<int> crescenti, decrescenti;
    ll missingC = C, missingD = D;
    for (int i = N - 2; i >= 0; i -= 2) {
        int d1 = i, d2 = 2 * N - 2 - i;
        if (missingC >= i + 1) {
            crescenti.emplace_back(d1);
            missingC -= i + 1;
        }
        if (missingC >= i + 1) {
            crescenti.emplace_back(d2);
            missingC -= i + 1;
        }
    }
    for (int i = 1; i < N; i += 2) {
        int d1 = i, d2 = -i;
        if (missingD >= N - i) {
            decrescenti.emplace_back(d1);
            missingD -= N - i;
        }
        if (missingD >= N - i) {
            decrescenti.emplace_back(d2);
            missingD -= N - i;
        }
    }
    return {crescenti, decrescenti};
}

#ifndef EVAL
int main() {
    ios_base::sync_with_stdio(false);
    int N;
    long long C, D;
    cin >> N >> C >> D;
    auto [crescenti, decrescenti] = disegna(N, C, D);
    for (int c: crescenti)
        cout << c << ' ';
    cout << '\n';
    for (int d: decrescenti) 
        cout << d << ' ';
    cout << '\n';
}
#endif
