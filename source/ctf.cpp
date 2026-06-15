#include <bits/stdc++.h>
using namespace std;

long long solve(long long n){
    int logN = log2(n);
    long long mod = 1LL << logN;
    return 2LL * (n % mod) + 1;
}

int main(){
    int Q; cin >> Q;
    vector<long long> N(Q);
    for(auto &u: N) cin >> u;
    for(auto &u: N) u = solve(u);
    for(auto  u: N) cout << u << "\n";
    return 0;
}