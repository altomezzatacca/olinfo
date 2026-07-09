#include "bits/stdc++.h"
using namespace std;

inline void solve(){
    int N; cin >> N;
        vector<long long> A(N);
        for(auto &u: A) cin >> u;
        vector<long long> B(N - 1);
        for(auto &u: B) cin >> u;
        long long l = 0, r = 0;
        for(auto u: A) r += u;
        for(auto u: B) r += u;
        r /= N; r++;
        while(r - l > 1){
            long long m = (l + r) >> 1;
            bool possible = 1;
            vector<long long> A1 = A, B1 = B;
            if(A1[0] + B1[0] < m) possible = 0;
            else if (A1[0] >= m);
            else {
                long long a = m - A1[0];
                A1[0] += a;
                B1[0] -= a;
            }
            for(int i = 1; i < N - 1; i++){
                A1[i] += B1[i - 1];
                if(A1[i] + B1[i] < m) possible = 0;
                else if (A1[i] >= m) continue;
                else {
                    long long a = m - A1[i];
                    A1[i] += a;
                    B1[i] -= a;
                }
            }
            if(A1[N - 1] + B1[N - 2] < m) possible = 0;
            if(possible) l = m;
            else r = m;
        }
        cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}