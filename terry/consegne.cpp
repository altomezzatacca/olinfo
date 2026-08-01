#include <bits/stdc++.h>
using namespace std;
constexpr static int sus = 15;

bool comp (array<long long, 2> A, array<long long, 2> B){
    return (A[0] + A[1] < B[0] + B[1]);
}

void solve(int t){
    int N; cin >> N;
    vector<long long> P(N);
    for(int i = 0; i < N; i++)
        cin >> P[i];
    vector<array<vector<array<long long, 2>>, 2>> dp(N);
    // dp[i][0] -> min se parto al minuto i, dp[i][1] -> min se non parto
    // dp[i][b][k][0] -> costo attuale, dp[i][b][k][1] -> pesci caricati sul furgone attualmente
    dp[0][0].push_back({0, 0});
    dp[0][1].push_back({0, 1});
    for(int i = 1; i < N; i++){
        long long best = 1e15;
        for(int k = 0; k < (int)dp[i - 1][1].size(); k++)
            best = min(best, dp[i - 1][1][k][0] + dp[i - 1][1][k][1]);
        dp[i][0].push_back({best, 0});
        dp[i][1].push_back({dp[i - 1][0][0][0] + P[i], 1});
        for(int k = 0; k < (int)dp[i - 1][1].size(); k++)
            dp[i][1].push_back({dp[i - 1][1][k][0] + dp[i - 1][1][k][1], dp[i - 1][1][k][1] + 1});
        sort(begin(dp[i][1]), end(dp[i][1]), comp);
        while((int)dp[i][1].size() > sus)
            dp[i][1].pop_back();
    }
    long long ans = 1e15;
    for(int k = 0; k < (int)dp[N - 1][1].size(); k++)
        ans = min(ans, dp[N - 1][1][k][0] + dp[N - 1][1][k][1]);
    ans = min(ans, dp[N - 1][0][0][0]);
    cout << "Case #" << t << ": ";
    cout << ans << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
        solve(t);
}