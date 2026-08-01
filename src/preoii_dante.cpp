#include "bits/stdc++.h"
using namespace std;

int rimembra(int N, int K, vector<int> V){
    if(K == 0){
        int current = 0, best = 0;
        for(int i = 0; i < N; i++){
            if(V[i] == 0){
                best = max(best, current);
                current = 0;
            } else current++;
        }
        return max(best, current);
    }
    int l = 0, r = 0;
    int ans = 1, cost = 1 - V[0], len = 1;
    while(r < N - 1){
        r++;
        if(!V[r]) cost++;
        len++;
        while(cost > K){
            if(!V[l]) cost--;
            len--;
            l++;
        }
        ans = max(ans, len);
    }
    return ans;
}