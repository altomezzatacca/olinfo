#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int x4 = x1 ^ x2 ^ x3, y4 = y1 ^ y2 ^ y3;
    cout << "Case #" << t << ": " << x4 << " " << y4 << "\n";
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