#include "bits/stdc++.h"
using namespace std;

int arrampicate(int N, string S){
    int &n = N;
    vector<array<int, 3>> dp(n + 1); // arrivo alla posizione i con movimento libero [0], verso dx [1] o sx [2]
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            if (dp[i][k] == -1) continue;
            if (S[i] == '=')
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
            if (S[i] == '#')
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][k] + 1);
            if (S[i] == '>' || S[i] == '?') {
                if (k == 0 || k == 1)
                    dp[i + 1][1] = max(dp[i + 1][1], dp[i][k]);
                else
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][k] + 1);
            }
            if (S[i] == '<' || S[i] == '?') {
                if (k == 0 || k == 2)
                    dp[i + 1][2] = max(dp[i + 1][2], dp[i][k]);
                else
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][k] + 1);
            }
        }
    }
    return max({dp[n][0], dp[n][1], dp[n][2]});
}
