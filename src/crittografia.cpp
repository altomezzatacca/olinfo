#include "bits/stdc++.h"
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, L; cin >> N >> L;
    string S; cin >> S;
    map<int, char> m;
    for(int i = 0; i < N; i++) m[i] = 0;
    bool possible = 1;
    for(int i = 0; possible && i < L; i++){
        if(S[i] < '0' || S[i] > N + '0' - 1) continue;
        int x = S[i] - '0';
        if(S[L - 1 - i] == S[i]) continue;
        if(S[L - 1 - i] >= '0' && S[L - 1 - i] <= '9') possible = 0;
        if(m[x] != 0 && S[L - 1 - i] != m[x]) possible = 0;
        else m[x] = S[L - 1 - i];
    }
    string word(N, 'a');
    for(int i = 0; i < N; i++){
        word[i] = m[i];
        if(m[i] == 0) possible = 0;
    }
    cout << (possible ? word : "impossibile");
}