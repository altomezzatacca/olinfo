#include <bits/stdc++.h>
using namespace std;

int presta(int N, int C, vector<int> P) {
	
	int r=0;
	sort(P.rbegin(), P.rend());
	
	while(C>0){
		C-=P[r];
		r++;
	}
	
    return r;
}
