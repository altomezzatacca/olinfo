#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int speedrunna(int N, int K, int a, int b){
	vector<int> temp(K+1);
	vector<int> dp(K+1, INF);
	
	for(int i = 0, t = 1, c = 1%K; i < N; i++, t = (t*a) % 1000, c = (c*b) % K){
		temp=dp;
		for(int k=0; k<=K; k++) dp[k]=INF;
		if(i==0) dp[1%K] = 1;
		dp[0] = min(dp[0], temp[K]);
		for(int j=0; j<=K; j++){
			int ix = min(j + c, K);
			dp[ix] = min(dp[ix], temp[j] + t);
		}
	}
	
	int ans = INF;
	for(int i=0; i<=K; i++) ans = min(ans, dp[i]);
	return ans;
}