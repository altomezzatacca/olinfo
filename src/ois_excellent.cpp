#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    string S;
    
    if(N <= 1) {
    	cout << -1;
    	return 0;
	}
    
    while (N >= 3){
    	N-=3;
    	for(int i = 0; i < 3; i++) S.push_back('1');
	}
	if(N % 3 == 2){
		S.push_back('1');
		S.push_back('5');
	} else if(N % 3 == 1){
		S.pop_back();
		for(int i = 0; i < 2; i++) S.push_back('5');
	}

    cout << S << endl; // print the result
    return 0;
}
