#include <bits/stdc++.h>
using namespace std;

int check_E(int N, vector<int> &A){
	int k=0;
	for(int i=0; i<N; i++){
		if(A[i]%2!=i%2) k++;
	}
	return k;
}

int check_O(int N, vector<int> &A){
	int k=0;
	for(int i=1; i<=N; i++){
		if(A[i-1]%2!=i%2) k++;
	}
	return k;
}

int traffico(int N, vector<int> S) {
    vector<int> A;
    for(auto u: S) A.push_back(u%2);
	int x=check_E(N, A);
	int y=check_O(N, A);
	return min(x, y);
}