#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            int x; cin >> x;
            v[i] += x;
        }
        if (v[i] > v[cur])
            cur = i;
        cout << cur + 1 << "\n";
    }

    return 0;
}
