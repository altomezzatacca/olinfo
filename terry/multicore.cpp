#include <bits/stdc++.h>
#define MAXN 300
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t, i;
    cin >> T;

    for (t = 1; t <= T; t++) {
        int N, B;
        int C[MAXN], P[MAXN];

        cin >> N >> B;
        for (i = 0; i < N; i++)
            cin >> C[i] >> P[i];
        vector<vector<int>> dp(N + 1, vector<int>(N * 200 + 5, -1));
        dp[0][0] = B;
        for(int i = 0; i < N; i++) { //scorro tutte le cpu
          int ix = i + 1;
          dp[ix] = dp[i];
          for(int j = 0; j < N * 200 + 5; j++){
            if(dp[i][j] == -1) continue;
            if(dp[i][j] >= P[i]) // possiamo comprare la cpu i
              dp[ix][j + C[i]] = max(dp[ix][j + C[i]], dp[i][j] - P[i]);
          }
        }
        int best = 0;
        for(int i = N * 200 + 4; i >= 0 && best == 0; i--)
          if(dp[N][i] != -1)
            best = i;
        cout << "Case #" << t << ": " << best << endl;
    }
}
