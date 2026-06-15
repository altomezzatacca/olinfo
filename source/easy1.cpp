#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> S(N);
	for (int i=0; i<N; i++) cin >>S[i];
	int x=S[0];
	for(int i=1; i<N; i++) if (S[i]>x) x=S[i];
	cout<<x;
	return 0;
}