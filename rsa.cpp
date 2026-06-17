#include <bits/stdc++.h>
using namespace std;

long long pow(int c, int d, int N){
    if(d == 0) return 1;
    if(d == 1) return c % N;
    long long x = pow(c, d >> 1, N);
    long long ans = (x * x) % N;
    if(d & 1) ans *= c;
    ans %= N;
    return ans;
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    for(int i = 0; i < L; i++)
        plaintext[i] = pow(messaggio[i], d, N);
    plaintext[L] = '\0';
}