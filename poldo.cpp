#include <bits/stdc++.h>
using namespace std;

int main() {
	
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
	int N;
    cin>>N;
    vector<int> P(N);
    
	for(int i=0;i<N;i++) {
        cin>>P[i];
    }
    
    vector<int> dp(N);
    for(int i=0;i<N;i++) {
        int max=1;
        for(int j=0;j<i;j++) {
            if(P[j]>P[i]) {
                if(dp[j]+1>max) {
                    max=dp[j]+1;
                }
            }
        }
        dp[i]=max;
    }
    
	int r=0;
    for(int i=0;i<N;i++) r=max(r,dp[i]);
    cout<<r;
    
    return 0;
}