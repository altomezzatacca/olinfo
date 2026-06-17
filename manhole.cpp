#include <bits/stdc++.h>
using namespace std;
constexpr static int mod = 10007;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int L, N, K;
	cin >> L >> N >> K;
    vector<int> V(N - 1), factorial(N);
    factorial[0] = 1;
	for (int i = 0; i < N - 1; i++) {
		cin >> V[i];
        factorial[i + 1] = (factorial[i] * (i + 1)) % mod;
	}
    vector<vector<int>> dp(N + 1, vector<int> (L + 1));
    dp[0][0] = 1;
    for(auto u: V){ // 0/1 knapsack
        for(int used = K - 1; used >= 0; used--){
            for(int l = 0; l <= L; l++){
                int ll = min(L, l + u);
                dp[used + 1][ll] = (dp[used + 1][ll] + dp[used][l]) % mod;
            }
        }
    }
      cout << (((dp[K][L] * factorial[K]) % mod) * factorial[N - K - 1]) % mod << "\n";
    return 0;
}