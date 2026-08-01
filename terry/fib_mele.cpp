#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, M, C;
    cin >> N >> M >> C;

    cout << "Case #" << t << ": " << min(C, N * M) << "\n";
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
