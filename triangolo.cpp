#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int N;
	cin >> N;
	vector<vector<int>> tri(N);
	for (int i=1; i<=N; i++){
		for (int j=0; j<i; j++){
			int l;
			cin >> l;
			tri[i-1].push_back(l);
		}
	}
	
	vector<vector<int>> V(N);
	V[0].push_back(tri[0][0]);
	for (int i=2; i<=N; i++){
		for (int j=0; j<i; j++){
			int l;
			if (j==i-1) l=V[i-2][j-1]+tri[i-1][j];
			else if (j==0) l=V[i-2][j]+tri[i-1][j];
			else l = max(V[i-2][j-1]+tri[i-1][j], V[i-2][j]+tri[i-1][j]);
			V[i-1].push_back(l);
		}
	}
	int ris=0;
	for (auto u:V[N-1]){
		ris = max (ris, u);
	}
	
	cout << ris;
	
	return 0;
}