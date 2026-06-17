#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;

int main(){

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int N, K; cin >> N >> K;
	vector<ll> T(N); for(auto &x: T) cin >> x;
	vector<ll> dp(N, -INF); dp[0]=0;
	vector<ll> temp(N);
	
	while(K--){ //simulo a mano ogni turno
		
		temp=dp; //inizializzo ogni volta temp e dp
		for(int i=0; i<N; i++) dp[i]=-INF;
		
		for(int i=0; i<N; i++){
			
			for(int a=3; a<=11; a++){ //simulo i tiri senza lanci doppi
				int ix = (i+a)%N;
				dp[ix] = max(dp[ix], temp[i] + T[ix]);
			}
			
			for(int a=2; a<=12; a+=2){ //simulo i tiri con un lancio doppio
				int ix = (i+a)%N;
				for(int b=3; b<=11; b++){
					int jx = (ix+b)%N;
					dp[jx] = max(dp[jx], temp[i] + T[ix] + T[jx]);
				}
			}
			
			for(int a=2; a<=12; a+=2){ //simulo i tiri con due lanci doppi
				int ix = (i+a)%N;
				for(int b=2; b<=12; b+=2){
					int jx = (ix+b)%N;
					for(int c=2; c<=12; c++){
						int kx = (jx+c)%N;
						dp[kx] = max(dp[kx], temp[i] + T[ix] + T[jx] + T[kx]);
					}
				}
			}
		}
	}
	
	ll ris = -INF;
	for(int i=0; i<N; i++) ris = max(ris, dp[i]);
	cout << ris;

	return 0;
}
