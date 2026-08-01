#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    cin >> c1 >> c2;

    int inizio = max(a1, max(b1, c1));
    int fine = min(a2, min(b2, c2));
    int risposta = fine - inizio;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
