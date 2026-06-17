// NOTE: it is recommended to use this even if you don't understand the following code.
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long Somma(deque<int> C){
	long long s=0;
	for (int i=1; i<C.size(); i++){
		s+=C[i];
	}
	return s;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;

    deque<int> C;
    for (int i = 0; i < N; ++i){
        int x;
		cin >> x;
        C.push_back(x);
	}
    long long M = 0;


    // INSERT YOUR CODE HERE
	if(K<=N){
		for(int i=0; i<K; i++){
			if(C[0]<=C[1]){
				M+=C[0];
			} else {
				M+=C[1];
				int x=C[0];
				C[0]=C[1];
				C[1]=x;
			}
			C.push_back(C[0]);
			C.pop_front();
		}
	} else {
		for(int i=0; i<N-1; i++){
			if(C[0]>C[1]){
				int x=C[0];
				C[0]=C[1];
				C[1]=x;
			}
			C.push_back(C[0]);
			C.pop_front();
		}
		long long somma=Somma(C);
		M+=somma*(K/(N-1));
		for (int i=0; i<K%(N-1); i++){
			M+=C[i+1];
		}
	}

    cout << M << endl;

    return 0;
}