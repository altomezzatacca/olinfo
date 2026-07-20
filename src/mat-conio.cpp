#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int N; cin>>N;
	vector<int> div;
	for(int i=1; i<=N; i++){
		if (N%i==0) div.push_back(i);
	}
	vector<int> DP(div.size(), 1);
	for(int i=1; i<div.size(); i++){
		for(int j=0; j<i; j++){
			if(div[i]%div[j]==0){
				DP[i]=max(DP[i], DP[j]+1);
			}
		}
	}
	int r=0;
	for(auto u: DP) r=max(r, u);
	cout<<r;

	return 0;
}
