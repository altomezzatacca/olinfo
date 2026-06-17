#include <bits/stdc++.h>
using namespace std;

int quadri(int N, long long M, int V[]) {
    long long l = 0, r = N + 1;
    vector<long long> prefix(N);
    prefix[0] = V[0];
    for(int i = 1; i < N; i++) prefix[i] = V[i] + prefix[i - 1];
    while(r - l > 1){
        long long m = (l + r) / 2;
        bool b = 1;
        for(int k = m - 1; k < N && b; k++){
            long long val = (k == m - 1 ? prefix[k] : prefix[k] - prefix[k - m]);
            if(val > M) b = 0;
        }
        if(b)
            l = m;
        else
            r = m;
    }
    return l;
}