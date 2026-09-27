#include "bits/stdc++.h"
using namespace std;
using ll = long long;

long long acquista(int N, int M, int L, vector<int> X, vector<int> T) {
    int &n = N, &m = M, &l = L;
    multiset<int> t;
    for (auto u: T) t.insert(u);
    sort(rbegin(X), rend(X));
    ll ans = 0;
    for (int i = 0; i < n && !t.empty(); i++) {
        int x = X[i];
        auto it = t.lower_bound(x);
        if (it != t.end()) {
            int y = *it;
            if (y - x < l)
                ans += l - y + x, t.erase(it);
        }
    }
    return ans;
}
