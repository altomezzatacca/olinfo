#include "bits/stdc++.h"
using namespace std;

int pulisci(int N, int M, vector<string> S) {
    int ans = N * M;
    vector<int> r0(N), r1(N), c0(M), c1(M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            S[i][j] == '0' ? r0[i]++ : r1[i]++;
            S[i][j] == '0' ? c0[j]++ : c1[j]++;
        }
    bool possible = 1;
    while(possible){
        int r_index = N;
        for(int i = 0; i < N; i++)
            if((r0[i] == 0 || r1[i] == 0) && ((r0[i] | r1[i]) != 0))
                r_index = i;
        if(r_index != N){
            r0[r_index] = r1[r_index] = 0;
            for(int i = 0; i < M; i++){
                if(S[r_index][i] != '2'){
                    ans--;
                    S[r_index][i] == '0' ? c0[i]-- : c1[i]--;
                }
                S[r_index][i] = '2';
            }
            continue;
        }
        int c_index = M;
        for(int i = 0; i < M; i++)
            if((c0[i] == 0 || c1[i] == 0) && ((c0[i] | c1[i]) != 0))
                c_index = i;
        if(c_index != M){
            c0[c_index] = c1[c_index] = 0;
            for(int i = 0; i < N; i++){
                if(S[i][c_index] != '2'){
                    ans--;
                    S[i][c_index] == '0' ? r0[i]-- : r1[i]--;
                }
                S[i][c_index] = '2';
            }
            continue;
        }
        possible = 0;
    }
    return ans;
}