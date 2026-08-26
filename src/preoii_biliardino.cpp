#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int n, logn = 20;
vector<ll> t;
vector<vector<ll>> up(logn), c(logn);
// binary lifting su un albero costruito su nxt

void inizia(int N, int T[]) {
    n = N;
    t.resize(n);
    for (int i = 0; i < logn; i++)
        up[i].resize(n + 1), c[i].resize(n + 1);
    for (int i = 0; i < n; i++)
        t[i] = T[i];
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= t[i])
            st.pop();
        int ix = (st.empty() ? n : st.top().second);
        up[0][i] = ix;
        c[0][i] = t[i] * (ix - i);
        st.emplace(t[i], i);
    }
    up[0][n] = n;
    c[0][n] = 0;
    for (int j = 1; j < logn; j++) {
        for (int i = n; i >= 0; i--) {
            up[j][i] = up[j - 1][up[j - 1][i]];
            c[j][i] = c[j - 1][i] + c[j - 1][up[j - 1][i]];
        }
    }
}

long long passaggio(int L, int R) {
    ll ans = 0;
    ll cur = L, r = R - 1;
    for (int j = logn - 1; j >= 0; j--) {
        if (up[j][cur] <= r) {
            ans += c[j][cur];
            cur = up[j][cur];
        }
    }
    if (cur <= r)
        ans += t[cur] * (r - cur + 1);
    return ans;
}

/*

int main() {
    int N, Q; cin >> N >> Q;
    int T[N];
    for (int i = 0; i < N; i++) cin >> T[i];
    inizia(N, T);
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        cout << passaggio(a, b) << "\n";
    }
}

*/
