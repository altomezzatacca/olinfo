#include <bits/stdc++.h>
using namespace std;

int N;
long long D;

int main() {
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> D;

	long long q = pow(10, N-1);
	long long res = (q + D - 1) / D;
	long long A = D * res;
	long long B = D * (res + 1);

	if(A >= 1LL*10*q || B >= 1LL*10*q) cout << 0 << " " << 0;
	else cout << A << ' ' << B << '\n'; // print the result
    return 0;
}