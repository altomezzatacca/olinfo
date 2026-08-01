#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N, M, K;
        cin >> N >> M >> K;

        if(M > N) swap(M, N);
        long long x = min(K, N - M);
        N -= x;
        K -= x;
        if(K > 0){
            N -= K/2;
            M -= K/2;
            if(K & 1) N--;
        }
        
        long long risposta = N * M;
        cout << "Case #" << test << ": ";
        cout << risposta << endl;
    }

    return 0;
}