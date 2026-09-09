#include "bits/stdc++.h"
using namespace std;

int viaggia(int n, vector<int> c) {
    int ans = c[0];
    int cur = ans;
    for (int i = 1; i < n; i++) {
        if (c[i] < ++cur)
            cur = c[i];
        ans += cur;
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> c(n);
    for (auto &u: c) cin >> u;
    cout << viaggia(n, c) << "\n";
}
