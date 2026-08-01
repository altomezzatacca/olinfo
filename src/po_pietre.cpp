#include <bits/stdc++.h>
using namespace std;
int Confronta(int a, int b);

int Trova(int N, int G){
	int l = max(0, G - N),
		r = min(N, G) + 1;
	while(r - l > 1){
		int m = (l + r) / 2;
		if(m == 0 || G - m + 1 == N + 1) {
			l = m;
			continue;
		}
		if(m == N + 1 || G - m + 1 == 0) {
			r = m;
			continue;
		}
		if(Confronta(m, G - m + 1 + N))
			r = m;
		else
			l = m;
	}	
	if(l == 0 || G - l == N + 1) 
		return G - l + N;
	if(l == N + 1 || G - l == 0) 
		return l;
	return Confronta(l, G - l + N) ? l : G - l + N;
}
