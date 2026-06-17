#include <bits/stdc++.h>
using namespace std;

int arrampicate(int N, string S) {
    vector<vector<int>> dp(N + 1, vector<int>(3, -1));
    dp[0][0] = 1;

    for(int i = 0; i < N; i++) {
        for(int d = 0; d < 3; d++) {
            if (dp[i][d] <0) continue;
            vector<char> scelte;
            if (S[i] == '?') scelte = {'<', '>'};
            else scelte = {S[i]};
            for(char c: scelte) {
                if(c == '=') {
                    dp[i+1][d] = max(dp[i+1][d], dp[i][d]);
                } else if(c == '#') {
                    dp[i+1][0] = max(dp[i+1][0], dp[i][d]+1);
                } else {
                    int nd = 1;
					if(c == '<') nd = 2;
                    if(d == 0 || d == nd)
                        dp[i+1][nd] = max(dp[i+1][nd], dp[i][d]);
                    else
                        dp[i+1][0] = max(dp[i+1][0], dp[i][d] + 1);
                }
            }
        }
    }

    return max({dp[N][0], dp[N][1], dp[N][2]});
}