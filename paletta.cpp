#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &V, int l, int m, int r){
	long long ans = 0;
	int a = m - l + 1,
		b = r - m;
	vector<int> A(a), B(b);
	for(int i = 0; i < a; i++)
		A[i] = V[i + l];
	for(int i = 0; i < b; i++)
		B[i] = V[i + m + 1];
	int i = l, iA = 0, iB = 0;
	while(iA < a && iB < b){
		if(A[iA] <= B[iB])
			V[i++] = A[iA++];
		else {
			V[i++] = B[iB++];
			ans += a - iA;
		}
	}
	while(iA < a)
		V[i++] = A[iA++];
	while(iB < b)
		V[i++] = B[iB++];
	return ans;
}

long long f(vector<int> &V, int l, int r){
	long long ans = 0;
	if(l != r){
		int m = (l + r) >> 1;
		ans += f(V, l, m);
		ans += f(V, m + 1, r);
		ans += merge(V, l, m, r);
	}
	return ans;
}

long long paletta_sort(int N, int V[]) {
	bool b = 1;
	vector<int> A, B; // A pari, B dispari
	for(int i = 0; i < N; i++){
		if(i % 2 != V[i] % 2)
			b = 0;
		if(i % 2) B.emplace_back(V[i]);
		else A.emplace_back(V[i]);
	}
	if(!b) return -1;
	long long ans = 0;
	ans += f(A, 0, A.size() - 1);
	ans += f(B, 0, B.size() - 1);
	return ans;
}