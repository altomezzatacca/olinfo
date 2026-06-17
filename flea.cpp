#include <bits/stdc++.h>
using namespace std;

// input data
int N;
string S;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    cin >> S;
	
	int l=0, r=0;
	
	for(int i=0; i<N; i++){
		if(S[i]=='L') l++;
		else r++;
	}

    cout << abs(r-l) << endl; // print the result
    return 0;
}
