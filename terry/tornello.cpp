#include <iostream>
#include <cstdio>
using namespace std;

int solve() {
    int N;
    cin >> N;
    int risposta = 0;  // memorizza qui la risposta
    int min_start = 0, peak = 0;
    int cur = 0;
    for (int i=0; i<N; i++) {
        int variazione;
        cin >> variazione;
        cur += variazione;
        min_start = min(min_start, cur);
        peak = max(peak, cur);
    }
    risposta = -min_start + peak;
    return risposta;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}