#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

void mat_mult(long long base[2][2], long long res[2][2]) {
    long long temp[2][2];
    
    temp[0][0] = (base[0][0] * res[0][0] + base[0][1] * res[1][0]) % mod;
    temp[0][1] = (base[0][0] * res[0][1] + base[0][1] * res[1][1]) % mod;
    temp[1][0] = (base[1][0] * res[0][0] + base[1][1] * res[1][0]) % mod;
    temp[1][1] = (base[1][0] * res[0][1] + base[1][1] * res[1][1]) % mod;
    
    res[0][0] = temp[0][0];
    res[0][1] = temp[0][1];
    res[1][0] = temp[1][0];
    res[1][1] = temp[1][1];
}

void mat_pow(long long base[2][2], long long exp, long long res[2][2]) {
    res[0][0] = 1; res[0][1] = 0;
    res[1][0] = 0; res[1][1] = 1;
    while (exp > 0) {
        if (exp % 2) {
        	mat_mult(base, res);
		}
        mat_mult(base, base);
		exp /= 2;
    }
}

int excellent (long long N){
	
	if (N==0) return 0;
	
	long long A[2][2] = {{2, 2}, {0, -1}}; //matrice costante
		
	int S[2] = {0, 1}; //stato di 0
	
	int ans;
	
	long long res[2][2];
	mat_pow(A, N, res);
	ans = (res[0][0] * S[0] + res[0][1] * S[1]) % mod;
	
	return ans;
	
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N;
        cin >> N;
        
        int ans = 0;
        
        ans = excellent(N-1);
        
        cout << ans << endl;
    }

    return 0;
}
