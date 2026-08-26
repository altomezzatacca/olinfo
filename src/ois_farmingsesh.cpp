#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct segtree {

    int n, m, vv, nodes;
    vector<ll> values;
    vector<ll> cnt; // numero di elementi nel sottoalbero di i
    vector<ll> sum; // somma del sottoalbero di i
    vector<int> root_a, root_b; // nodo che era radice in un certo momento
    vector<int> left, right; // figli a sinistra e destra di un nodo

    inline int insert_node(int prv, int l, int r, int ix, ll val) {
        int cur = ++nodes; // 1-indexed per poter fare prefix
        if (l + 1 == r) {
            cnt[cur] = cnt[prv] + 1;
            sum[cur] = sum[prv] + val;
            return cur;
        }
        int m = (l + r) >> 1;
        if (ix < m) {
            left[cur] = insert_node(left[prv], l, m, ix, val);
            right[cur] = right[prv];
        } else {
            left[cur] = left[prv];
            right[cur] = insert_node(right[prv], m, r, ix, val);
        }
        cnt[cur] = cnt[left[cur]] + cnt[right[cur]];
        sum[cur] = sum[left[cur]] + sum[right[cur]];
        return cur;
    }

    inline void build(const vector<int>& a, const vector<int> &b) {

        n = a.size();
        m = b.size();
        nodes = 0; // nodo corrente
        
        set<int> s;
        for (auto u: a) s.insert(u);
        for (auto u: b) s.insert(u);
        for (auto u: s) values.emplace_back(u);
        vv = values.size();

        int max_nodes = (n + m + 1) * (ceil(log2(vv)) + 2);
        cnt.resize(max_nodes);
        sum.resize(max_nodes);
        left.resize(max_nodes);
        right.resize(max_nodes);
        root_a.resize(n + 2);
        root_b.resize(m + 2);

        for (int i = 1; i <= n; i++) {
            int ix = lower_bound(begin(values), end(values), a[i - 1]) - begin(values);
            root_a[i] = insert_node(root_a[i - 1], 0, vv, ix, a[i - 1]);
        }
        for (int i = 1; i <= m; i++) {
            int ix = lower_bound(begin(values), end(values), b[i - 1]) - begin(values);
            root_b[i] = insert_node(root_b[i - 1], 0, vv, ix, b[i - 1]);
        }
    }

    inline ll solve(int al, int ar, int bl, int br, int nl, int nr, ll k) { // query contemporanea su a e b
        if (nl + 1 == nr)
            return values[nl] * min(k, cnt[ar] - cnt[al] + cnt[br] - cnt[bl]);
        int nm = (nl + nr) >> 1;
        ll avr = cnt[right[ar]] - cnt[right[al]] + cnt[right[br]] - cnt[right[bl]]; // numero di valori disponibili a dx
        if (avr >= k)
            return solve(right[al], right[ar], right[bl], right[br], nm, nr, k);
        else
            return sum[right[ar]] - sum[right[al]] + sum[right[br]] - sum[right[bl]] // nodi a destra
                 + solve(left[al], left[ar], left[bl], left[br], nl, nm, k - avr); // restanti nodi a sinistra
    }

    inline ll query(int l1, int r1, int l2, int r2) {
        int nn = r1 - l1 + 1;
        return solve(root_a[l1 - 1], root_a[r1], root_b[l2 - 1], root_b[r2], 0, vv, nn);
    }

};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    vector<int> B(M);
    for (int i = 0; i < M; ++i)
        cin >> B[i];
    segtree seg;
    seg.build(A, B);

    for (int i = 0; i < Q; i++) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        l1++, r1++, l2++, r2++; // 1-indexed
        cout << seg.query(l1, r1, l2, r2) << "\n";
    }

    return 0;
}

