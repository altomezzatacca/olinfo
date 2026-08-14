#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// se sfrondo i allora sfrondo [i, n - 1]

ll carica(int N, int K, vector<int> A){
    int &n = N, &k = K;
    vector<int> &a = A;
    if(n == 1) return a[0];
    vector<ll> b(n), c(n);
    b[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
        b[i] = b[i + 1] + a[i];
    for(int i = 0; i < n; i++)
        c[i] = 1LL * (n - i) * k + a[n - 1];
    ll ix = -1, best = 0; // best contiene il valore massimo da sottrarre -> costo minimo
    for(int i = 0; i < n; i++){
        if(b[i] - c[i] > best){
            best = b[i] - c[i];
            ix = i;
        }
    }
    ll ans = (ix == -1 ? b[0] : b[0] - b[ix] + k * (n - ix) + a[n - 1]);
    return ans;
}

#ifndef EVAL
int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &u: a) cin >> u;
    cout << carica(n, k, a) << endl;
    return 0;
}
#endif
