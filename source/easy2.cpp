#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> a(N), b(N);
	for (int i=0; i<N; i++) {
		cin >>a[i];
		cin >>b[i];
	}
	int x=-1;
	for(int i=0; i<N; i++) if ((a[i]+b[i])%2==0 && a[i]+b[i]>x) x=a[i]+b[i];
	cout<<x;
	return 0;
}