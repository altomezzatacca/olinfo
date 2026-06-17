#include <bits/stdc++.h>
using namespace std;

int dividi(int N, vector<int> V) {
    int sum = 0;
    for(auto u: V) sum += u;
    vector<vector<bool>> dp(2, vector<bool> (sum + 1));
    dp[0][0] = dp[1][0] = 1;
    for(int j = 0; j < N; j++){
        int &k = V[j];
        for(int i = sum - k; i >= 0; i--)
            if(dp[0][i])
                dp[1][i + k] = 1;
        dp[0] = dp[1];
    }
    int ans = 1e9;
    for(int i = 0; i < sum + 1; i++)
        if(dp[0][i])
            ans = min(ans, abs(sum - 2 * i));
    return ans;
}

#ifndef EVAL

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    vector<int> V(N);
    for(auto &x: V) cin >> x;

    cout << dividi(N, V) << endl;
}

#endif