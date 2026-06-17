#include <bits/stdc++.h>
using namespace std;

int tempo_massimo(int N, int a[], int b[]){
	vector<int> V(N);
	V[0] = max(a[0],        b[0]);
	V[1] = max(V[0] + a[1], b[1]);
	for (int i = 2; i < N; i++)
		V[i] = max(V[i - 1] + a[i], V[i - 2] + b[i]);
    return V[N-1];
}