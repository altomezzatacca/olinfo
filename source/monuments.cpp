#include <bits/stdc++.h>
using namespace std;

int demolish(int N, int K, int L, vector<int> S) {
	if (L==K) return N;
	if (N==2*K) return 2*L;
	int mod = 2*K;
	
	sort(S.begin(), S.end());
	
	int best = N;
	
	for (int i=0; i<N; i++){
		int x=S[i]+1;
		
		int a1 = lower_bound(S.begin(), S.end(), x) - S.begin();
		int b1 = lower_bound(S.begin(), S.end(), x+L) - S.begin();
		int c1 = b1 - a1;
		
		int a2 = lower_bound(S.begin(), S.end(), x+K) - S.begin();
		int b2 = lower_bound(S.begin(), S.end(), x+L+K) - S.begin();
		int c2 = b2 - a2;
		
		best = min (best, c1+c2);
	}
	
	return best;
}



int main() {

	freopen("input.txt","r",stdin);

    int N, K, L;

    scanf("%d%d%d",&N,&K,&L);
    vector<int> S;
    for(int i = 0; i < N;i++){
		int x;
        scanf("%d",&x);
        S.push_back(x);
        S.push_back(x+2*K);
        S.push_back(x+4*K);
	}

    cout << demolish(N, K, L, S);
    
    return 0;
}