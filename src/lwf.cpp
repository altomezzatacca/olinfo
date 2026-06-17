#include <bits/stdc++.h>
using namespace std;

vector<char>answer;

string fibo(int N){
	vector<int> fib;
	fib.push_back(1);
	fib.push_back(1);
	while (fib[fib.size()-1]<N){
		int k=fib[fib.size()-1] + fib[fib.size()-2];
		fib.push_back(k);
	}
	if (fib[fib.size()-1] == N) {
		//return "1";
	} else fib.pop_back();

	string S;
	S.resize(fib.size());
	for (int i=0; i<fib.size(); i++){
		S[i]='0';
	}

	int k=0;
	
	for (int i=fib.size()-1; i>=0; i--){
		if (k+fib[i]<=N){
			k+=fib[i];
			S[i]='1';
		}
	}
	
	return S;
}

int main(){
	
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int N;
	cin >> N;

	string S;
	S = fibo(N);
	
	cout << S;

	return 0;
}