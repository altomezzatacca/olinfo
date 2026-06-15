#include <bits/stdc++.h>
using namespace std;
constexpr static int mod = 32749;

void mat_mult(int base[2][2], int res[2][2]) {
    int temp[2][2];
    
    temp[0][0] = (base[0][0] * res[0][0] + base[0][1] * res[1][0]) % mod;
    temp[0][1] = (base[0][0] * res[0][1] + base[0][1] * res[1][1]) % mod;
    temp[1][0] = (base[1][0] * res[0][0] + base[1][1] * res[1][0]) % mod;
    temp[1][1] = (base[1][0] * res[0][1] + base[1][1] * res[1][1]) % mod;
    
    res[0][0] = temp[0][0];
    res[0][1] = temp[0][1];
    res[1][0] = temp[1][0];
    res[1][1] = temp[1][1];
}

void mat_pow(int base[2][2], int exp, int res[2][2]) {
    res[0][0] = 1; res[0][1] = 0;
    res[1][0] = 0; res[1][1] = 1;
    while (exp > 0) {
        if (exp % 2) mat_mult(base, res);
        mat_mult(base, base);
		exp /= 2;
    }
}

int main() {
    
	int N, K, E;
	cin >> N;
	
	int A[2][2] = {{3,2},{3,3}};
	int res[2][2];
	
	mat_pow(A, N, res);
	
	K = res[0][0];
	E = res[1][0];
	
	cout << K << " " <<E;	

    return 0;
}
