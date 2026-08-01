#include "bits/stdc++.h"
using namespace std;

long long riciclo(int N, int M, vector<int> T, vector<int> P) {
    long long ans = 0;
    sort(begin(T), end(T));
    for(int k = 0; k < M; k++){
        if(P[k] == 0) continue;
        for(int i = 0; i < N && P[k] > 0; i++)
            if(T[i] & (1 << k)){
                T[i] ^= (1 << k);
                P[k]--;
                ans++;
            }
        for(int i = 0; i < N && P[k] > 0; i++){
            long long x = T[i] >> k;
            if(x < 1) continue;
            x = min(x, 1LL * P[k]);
            P[k] -= x;
            T[i] -= (x << k);
            ans += x;
        }
    }
    return ans;
}
