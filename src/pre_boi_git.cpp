#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct segtree {
    struct node {
        node *l, *r;
        ll sum, lazy;
        node(ll x) : l(nullptr), r(nullptr), sum(x), lazy(0) {}
        node(node *l, node *r) : l(l), r(r), sum(0), lazy(0) {
            if (l) sum += l -> sum;
            if (r) sum += r -> sum;
        }
    };
    int enne, curv = 0;
    vector<node*> versions;
    node* build(const vector<int>& a, int nl, int nr) {
        if (nr - nl == 1)
            return new node(1LL * a[nl]);
        int nm = (nl + nr) >> 1;
        return new node(build(a, nl, nm), build(a, nm, nr));
    }
    node* prupdate(node* n, int nl, int nr, ll x) {
        node* nn = new node(*n);
        nn -> sum += x * (nr - nl);
        nn -> lazy += x;
        return nn;
    }
    pair <node*, node*> propagate(node*n, int nl, int nr) {
        int nm = (nl + nr) >> 1;
        node* l = n -> l;
        node* r = n -> r;
        if (n -> lazy != 0) {
            l = prupdate(n -> l, nl, nm, n -> lazy);
            r = prupdate(n -> r, nm, nr, n -> lazy);
        }
        return {l, r};
    }
    ll qsum(node* n, int nl, int nr, int ql, int qr, ll lazy) {
        if (qr <= nl || nr <= ql) return 0;
        if (ql <= nl && nr <= qr) return n -> sum + lazy * (nr - nl);
        int nm = (nl + nr) >> 1;
        return qsum(n -> l, nl, nm, ql, qr, lazy + n -> lazy) + qsum(n -> r, nm, nr, ql, qr, lazy + n -> lazy);
    }
    node* update(node* n, int nl, int nr, int ql, int qr, ll x) {
        if (qr <= nl || nr <= ql) return n;
        if (ql <= nl && nr <= qr) return prupdate(n, nl, nr, x);
        int nm = (nl + nr) >> 1;
        auto [l, r] = propagate(n, nl, nr);
        node* nwl = update(l, nl, nm, ql, qr, x);
        node* nwr = update(r, nm, nr, ql, qr, x);
        return new node(nwl, nwr);
    }
    node* rollback(node* cur, node* old, int nl, int nr, int ql, int qr) {
        if (qr <= nl || nr <= ql) return cur;
        if (ql <= nl && nr <= qr) return old;
        int nm = (nl + nr) >> 1;
        auto [curl, curr] = propagate(cur, nl, nr);
        auto [oldl, oldr] = propagate(old, nl, nr);
        node* l = rollback(curl, oldl, nl, nm, ql, qr);
        node* r = rollback(curr, oldr, nm, nr, ql, qr);
        return new node(l, r);
    }
};

segtree seg;

void inizia(int N, vector<int> A){
    seg.enne = N;
    seg.versions.emplace_back(seg.build(A, 0, seg.enne));
}

void incrementa(int l, int r, int x){
    seg.versions.emplace_back(seg.update(seg.versions[seg.curv++], 0, seg.enne, l, r, 1LL * x));
}

void resetta(int l, int r, int v){
    seg.versions.emplace_back(seg.rollback(seg.versions[seg.curv++], seg.versions[v], 0, seg.enne, l, r));
}

long long somma(int l, int r){
    return seg.qsum(seg.versions[seg.curv], 0, seg.enne, l, r, 0);
}
