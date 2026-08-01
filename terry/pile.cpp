#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        ans += max(a, max(b, c));
    }
    cout << "Case #" << t << ": " << ans << "\n";
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