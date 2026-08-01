#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXM = 1000;
int dp[MAXN + 1][MAXM + 1];

int solve(int n, int m, vector<int> &N, vector<int> &M){
	if(n == 0) return 0;
	if(m == 0) return n;
	if(dp[n][m] != -1) return dp[n][m];
	int ans = max(solve(n, m - 1, N, M), solve(n - 1, m, N, M) + 1);
	if(N[(int)N.size() - n] < M[(int)M.size() - m])
		ans = max(ans, solve(n - 1, m - 1, N, M) + 2);
	return dp[n][m] = ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, t;
    cin >> T;
    for (t = 1; t <= T; t++) {
	    int n, m;
	    cin >> n >> m;
	    vector<int> N(n), M(m);
	    for (int i = 0; i < n; i++) cin >> N[i];
	    for (int i = 0; i < m; i++) cin >> M[i];
	    memset(dp, -1, sizeof dp);
        cout << "Case #" << t << ": " << solve(n, m, N, M) << endl;
    }
    return 0;
}