#include <bits/stdc++.h>
using namespace std;

long long solve(){
    long long A, B, K; cin >> A >> B >> K;
    long long sum = A + B + K;
    set<long long> S;
    for(long long i = 1; i * i <= sum; i++){
        if(sum % i == 0){
            S.insert(i);
            S.insert(sum / i);
        }
    }
    if(A < B) swap(A, B); // wlog A >= B
    vector<long long> V;
    for(auto u: S) V.emplace_back(u);
    reverse(begin(V), end(V));
    long long ans = 0;
    for(int i = 1; i < (int)V.size() && ans == 0; i++){
        long long d = V[i];
        if(A < d) ans = d;
        else {
            long long a = A % d, b = B % d;
            if(a == 0) a = d;
            if(b == 0) b = d;
            if(K >= 2 * d - a - b) ans = d;
        }
    }
    return ans;
}

int main(){
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}