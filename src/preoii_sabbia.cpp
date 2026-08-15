#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct segtree {
    struct node {
        ll v;
        int l, r;
    };
    int sz = 1;
    vector<node> v;
    segtree (int n, vector<int> a) {
        while (sz < n) sz <<= 1;
        v.resize(2 * sz);
        for (int i = 0; i < n; v[i + sz].l = i, v[i + sz].r = i + 1, i++)
            v[i + sz].v = a[i];
        for (int i = n; i < sz; v[i + sz].l = i, v[i + sz].r = i + 1, i++)
            v[i + sz].v = 0;
        for (int i = sz - 1; i > 0; v[i].l = v[2 * i].l, v[i].r = v[2 * i + 1].r, i--)
            v[i].v = v[2 * i].v + v[2 * i + 1].v;
    }
    ll get_sum(int node, int l, int r) {
        int nl = v[node].l, nr = v[node].r;
        if (r <= nl || nr <= l) return 0;
        if (l <= nl && nr <= r) return v[node].v;
        ll ans = 0;
        ans += get_sum(2 * node, l, r);
        ans += get_sum(2 * node + 1, l, r);
        return ans;
    }
    void update(int u, ll x) {
        u += sz;
        v[u].v -= x;
        while (u >>= 1)
            v[u].v = v[2 * u].v + v[2 * u + 1].v;
    }
};

long long alleggerisci(int N, int M, vector<int> V, vector<int> L, vector<int> R, vector<long long> K) {
    int &n = N, &m = M;
    ll ans = 0;
    segtree seg = segtree(n, V);
    vector<array<ll, 3>> query(m);
    for(int i = 0; i < m; i++)
        query[i] = {L[i], R[i], K[i]};
    sort(begin(query), end(query), [&](array<ll, 3> a, array<ll, 3> b){
        return a[1] < b[1];
    }); // ordino per r crescente
    for (int i = 0; i < m; i++) {
        auto [l, r, k] = query[i];
        ll sum = seg.get_sum(1, l, r + 1);
        if (sum <= k) continue;
        seg.update(r, sum - k);
        ans += sum - k;
    }
    return ans;
}
