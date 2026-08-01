#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, L, D;
    cin >> N >> L >> D;
    vector<int> X(N), P(N), S(N);
    for (int i = 0; i < N; i++) 
        cin >> X[i] >> P[i] >> S[i];
    vector<array<int, 3>> events(N);
    for(int i = 0; i < N; i++)
        events[i][0] = S[i], events[i][1] = P[i], events[i][2] = X[i];
    sort(events.begin(), events.end());
    vector<int> dp(N);
    for(int i = 0; i < N; i++){
        auto[t1, p1, x1] = events[i];
        dp[i] = (x1 <= t1 ? p1 : -1);
        for(int j = 0; j < i; j++){
            auto [t2, p2, x2] = events[j];
            if(abs(x1 - x2) <= t1 - t2 && dp[j] != -1)
                dp[i] = max(dp[i], dp[j] + p1);
        }
    }
    int best = 0;
    for(auto u: dp) best = max(best, u);
    cout << "Case #" << t << ": " << best << "\n";
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