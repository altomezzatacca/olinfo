#include "bits/stdc++.h"
using namespace std;

struct venice{
    long long water = 0;
    map<long long, long long> m;
    void insert(long long p, long long s){
        auto it = m.lower_bound(p + water);
        if(it != m.end() && it -> second <= s) return;
        m[p + water] = s;
        it = m.find(p + water);
        while(it != m.begin()){
            if(prev(it) -> second >= s) m.erase(prev(it));
            else break;
        }
    }
    void update(long long d){
        water += d;
    }
    long long get(long long p){
        auto ans = m.lower_bound(p + water);
        return (ans == m.end() ? -1 : ans -> second);
    }
};

int main() {
    int N, D; cin >> N >> D;
    vector<long long> L(N), P(N), S(N), T(N);
    for(int i = 0; i < N; i++)
        cin >> L[i] >> P[i] >> S[i] >> T[i];
    auto findstart = [&] (int i, long long x) -> long long{ // primo segnale del nodo i
        if(x < S[i]) return S[i];
        x -= S[i];
        x = T[i] * (1 + x / T[i]);
        return S[i] + x;
    };
    venice v;
    v.insert(P[0], S[0]);
    for(int i = 1; i < N - 1; i++){
        v.update(D);
        long long x = v.get(L[i]);
        if(x == -1) continue;
        v.insert(P[i], findstart(i, x));
    }
    v.update(D);
    long long ans = v.get(L[N - 1]);
    cout << (ans == -1 ? -1 : findstart(N - 1, ans));
}


// Soluzione alternativa con Segment Tree
// la condizione: P[i] - (j - i) * D >= L[j] diventa: P[i] + i * D >= L[j] + j * D
// chiamando questi valori pp[i] e ll[j], metto in un segtree tutti i pp[i]
// e per ogni j guardo in O(log N) il minimo start time di un pp[i] >= ll[j]

/* struct segtree{
    int sz = 1;
    vector<long long> t;
    segtree(int n){
        while(sz < n) sz <<= 1;
        t.resize(2 * sz);
        for(int i = 0; i < sz; i++)
            t[sz + i] = 1e18;
        for(int i = sz - 1; i > 0; i--)
            t[i] = min(t[2 * i], t[2 * i + 1]);
    }
    void update(int i, long long x){
        i += sz;
        t[i] = x;
        while(i > 1){
            i >>= 1;
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
    long long query(int node, int l, int r, int ql, int qr){
        if(qr <= l || r <= ql) return 1e18;
        if(ql <= l && r <= qr) return t[node];
        int m = (l + r) >> 1;
        return min(query(2 * node, l, m, ql, qr), query(2 * node + 1, m, r, ql, qr));
    }
};

int main() {
    int N, D; cin >> N >> D;
    vector<long long> L(N), P(N), S(N), T(N);
    for(int i = 0; i < N; i++)
        cin >> L[i] >> P[i] >> S[i] >> T[i];
    auto findstart = [&] (int i, long long x) -> long long{ // primo segnale del nodo i
        if(x < S[i]) return S[i];
        x -= S[i];
        x = T[i] * (1 + x / T[i]);
        return S[i] + x;
    };
    vector<pair<long long, int>> pp(N);
    vector<long long> ll(N);
    map<int, int> m;
    for(int i = 0; i < N; i++){
        pp[i] = {P[i] + 1LL * i * D, i};
        ll[i] = L[i] + 1LL * i * D;
    }
    sort(begin(pp), end(pp));
    for(int i = 0; i < N; i++){
        m[pp[i].second] = i;
        ll[i] = lower_bound(begin(pp), end(pp), make_pair(ll[i], -1)) - begin(pp); // bug subdolissimo >:(
    }
    segtree seg = segtree(N);
    seg.update(m[0], S[0]);
    for(int i = 1; i < N; i++){
        long long act = seg.query(1, 0, seg.sz, ll[i], seg.sz);
        if(act != 1e18) seg.update(m[i], findstart(i, act));
    }
    long long ans = seg.query(1, 0, seg.sz, ll[N - 1], seg.sz);
    cout << (ans == 1e18 ? -1 : findstart(N - 1, ans));
} */