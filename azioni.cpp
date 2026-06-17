#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N; cin >> N;
	vector<int> V(N);
	for(int i=0; i<N; i++) cin >> V[i];
	int r=0;
	for(int i=0; i<N-1; i++) r = max(r, abs(V[i]-V[i+1]));
	cout<<r;
	
	return 0;
}