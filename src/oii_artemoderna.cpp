#include <bits/stdc++.h>
using namespace std;

bool ordina(int N, vector<int> V, vector<int> &L) {
    L={};
    int cons=1;
    for(int i=1; i<N; i++){
    	if(V[i]>V[i-1]) {
    		L.push_back(cons);
    		cons=0;
		}
		cons++;
	}
	L.push_back(cons);
	
	int ix=0;
	for(int i=0; i<L.size(); i++){
		reverse(V.begin() + ix, V.begin() + ix + L[i]);
		ix+=L[i];
	}
    
    vector<int> Q = V;
    sort(Q.begin(), Q.end());
    if (V==Q) return 1;
	return 0;
}
