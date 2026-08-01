#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> R[i];
    }

    long long dp[N][2][2][2];
    // 0 -> L, 1 -> R
    dp[2][0][0][0] = dp[2][1][1][1] = -1;
  
    dp[2][1][0][0] = R[2] + L[1] + L[0];
    dp[2][1][0][1] = R[2] + L[1] + R[0];
    dp[2][1][1][0] = R[2] + R[1] + L[0];
  
    dp[2][0][0][1] = L[2] + L[1] + R[0];
    dp[2][0][1][0] = L[2] + R[1] + L[0];
    dp[2][0][1][1] = L[2] + R[1] + R[0];

    for(int i = 3; i < N; i++){
      dp[i][1][0][0] = R[i] + dp[i - 1][0][0][1];
      dp[i][1][0][1] = R[i] + min(dp[i - 1][0][1][0], dp[i - 1][0][1][1]);
      dp[i][1][1][0] = R[i] + min(dp[i - 1][1][0][0], dp[i - 1][1][0][1]);
    
      dp[i][0][0][1] = L[i] + min(dp[i - 1][0][1][0], dp[i - 1][0][1][1]);
      dp[i][0][1][0] = L[i] + min(dp[i - 1][1][0][0], dp[i - 1][1][0][1]);
      dp[i][0][1][1] = L[i] + dp[i - 1][1][1][0];
    }
    long long risposta = 1e15;
    risposta = min(risposta, dp[N - 1][0][0][1]);
    risposta = min(risposta, dp[N - 1][0][1][0]);
    risposta = min(risposta, dp[N - 1][0][1][1]);
    risposta = min(risposta, dp[N - 1][1][0][1]);
    risposta = min(risposta, dp[N - 1][1][1][0]);
    risposta = min(risposta, dp[N - 1][1][0][0]);

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