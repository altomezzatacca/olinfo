#include "bits/stdc++.h"
using namespace std;

struct node{
    int l, r;
    long long sm, mn; // sum, min
    bool b_usm, b_ust; // has sum update, has set update
    long long usm = 0, ust = 0; // update sum, update set
};

struct segtree{
    int sz = 1;
    vector<node> t;
    segtree(){}
    segtree(vector<long long> a){
        int n = a.size();
        while(sz < n) sz <<= 1;
        t.resize(2 * sz);
        for(int i = 0; i < n; i++){
            t[sz + i].sm = a[i];
            t[sz + i].mn = a[i];
            t[sz + i].l = i;
            t[sz + i].r = i + 1;
        }
        for(int i = n; i < sz; i++){
            t[sz + i].sm = 0;
            t[sz + i].mn = 1e9;
            t[sz + i].l = i;
            t[sz + i].r = i + 1;
        }
        for(int i = sz - 1; i >= 1; i--){
            t[i].sm = t[2 * i].sm + t[2 * i + 1].sm;
            t[i].mn = min(t[2 * i].mn, t[2 * i + 1].mn);
            t[i].l = t[2 * i].l;
            t[i].r = t[2 * i + 1].r;
        }
    }
    void propagate(int node){
        if(t[node].b_ust){
            t[node].sm = t[node].ust * (t[node].r - t[node].l);
            t[node].mn = t[node].ust;
            if(node < sz){ // non è una foglia -> propago ai figli
                t[2 * node].b_ust = 1;
                t[2 * node].b_usm = 0;
                t[2 * node].ust = t[node].ust;
                t[2 * node].usm = 0;
                t[2 * node + 1].b_ust = 1;
                t[2 * node + 1].b_usm = 0;
                t[2 * node + 1].ust = t[node].ust;
                t[2 * node + 1].usm = 0;
            }
            t[node].ust = 0;
            t[node].b_ust = 0;
        }
        if(t[node].b_usm){
            t[node].sm += t[node].usm * (t[node].r - t[node].l);
            t[node].mn += t[node].usm;
            if(node < sz){ // propago ai figli
                t[2 * node].b_usm = 1;
                t[2 * node].usm += t[node].usm;
                t[2 * node + 1].b_usm = 1;
                t[2 * node + 1].usm += t[node].usm;
            }
            t[node].usm = 0;
            t[node].b_usm = 0;
        }
    }
    long long get_sum(int node, int ql, int qr){
        long long ans = 0;
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return 0;
        if(ql <= t[node].l && t[node].r <= qr){
            ans += t[node].sm;
        } else if(node < sz){
            ans += get_sum(2 * node    , ql, qr);
            ans += get_sum(2 * node + 1, ql, qr);
        }
        return ans;
    }
    long long get_min(int node, int ql, int qr){
        long long ans = 1e18;
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return 1e18;
        if(ql <= t[node].l && t[node].r <= qr){
            ans = min(ans, t[node].mn);
        } else if(node < sz){
            ans = min(ans, get_min(2 * node    , ql, qr));
            ans = min(ans, get_min(2 * node + 1, ql, qr));
        }
        return ans;
    }
    void add(int node, int ql, int qr, long long x){
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return;
        if(ql <= t[node].l && t[node].r <= qr){
            t[node].b_usm = 1;
            t[node].usm += x;
            propagate(node);
        } else if(node < sz){
            add(2 * node    , ql, qr, x);
            add(2 * node + 1, ql, qr, x);
            t[node].sm = t[2 * node].sm + t[2 * node + 1].sm;
            t[node].mn = min(t[2 * node].mn, t[2 * node + 1].mn);
        }
    }
    void set_range(int node, int ql, int qr, long long x){
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return;
        if(ql <= t[node].l && t[node].r <= qr){
            t[node].b_usm = 0;
            t[node].usm = 0;
            t[node].b_ust = 1;
            t[node].ust = x;
            propagate(node);
        } else if(node < sz){
            set_range(2 * node    , ql, qr, x);
            set_range(2 * node + 1, ql, qr, x);
            t[node].sm = t[2 * node].sm + t[2 * node + 1].sm;
            t[node].mn = min(t[2 * node].mn, t[2 * node + 1].mn);
        }
    }
    int lower_bound(int node, int ql, int qr, long long x){
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return 1e9;
        if(t[node].mn > x) return 1e9;
        if(node >= sz)
            return node - sz;
        int ans = lower_bound(2 * node, ql, qr, x);
        return (ans == 1e9 ? lower_bound(2 * node + 1, ql, qr, x) : ans);
    }
};

segtree seg;

void init(vector<long long> a) {
	seg = segtree(a);
}

long long get_sum(int l, int r) {
    return seg.get_sum(1, l, r);
}

void add(int l, int r, long long x) {
    seg.add(1, l, r, x);
}

void set_range(int l, int r, long long x) {
    seg.set_range(1, l, r, x);
}

long long get_min(int l, int r) {
    return seg.get_min(1, l, r);
}

int lower_bound(int l, int r, long long x) {
	return (seg.lower_bound(1, l, r, x) == 1e9 ? -1 : seg.lower_bound(1, l, r, x));
}