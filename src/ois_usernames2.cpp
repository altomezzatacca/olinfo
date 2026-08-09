#include "bits/stdc++.h"
using namespace std;

bool comp(string x, string y){
    if((int)x.size() != (int)y.size()) return (int)x.size() < (int)y.size();
    return x < y;
}

int main(){
    string A; cin >> A;
    int N; cin >> N;
    vector<string> S(N);
    for(auto &u: S) cin >> u;
    int ans = 0;
    sort(begin(S), end(S), comp);
    for(int i = 0; i < N; i++)
        if(S[i] == (ans == 0 ? A : A + to_string(ans)))
            ans++;
    cout << (ans == 0 ? A : A + to_string(ans)) << "\n";
}
