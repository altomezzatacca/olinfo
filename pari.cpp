#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	string S;
	switch (N%2){
		case 0:
			S="pari";
			break;
		case 1:
			S="dispari";
			break;
	}
	cout << S;
	return 0;
}