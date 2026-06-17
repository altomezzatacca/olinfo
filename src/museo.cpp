#include <bits/stdc++.h>
using namespace std;
int sz; vector<int> st;
//sia per i nodi che per le query: [l, r)

void inizia(int N, vector<int> A) {
    sz = 1;
    while(sz < N) sz <<= 1;
    st.resize(2 * sz);
    for(int i = 0; i < N; i++)
        st[sz + i] = A[i];
    for(int i = sz - 1; i > 0; i--)
        st[i] = max(st[2 * i], st[2 * i + 1]);
}

void update(int node, int nl, int nr, int P, int X){
    if(nr - nl == 1) st[node] = X;
    else {
        int nm = (nl + nr) >> 1;
        if(P < nm) update(2 * node, nl, nm, P, X);
        else update(2 * node + 1, nm, nr, P, X);
        st[node] = max(st[2 * node], st[2 * node + 1]);
    }
}

int query(int node, int nl, int nr, int ql, int qr){
    if(qr <= nl || nr <= ql) return 0;
    if(ql <= nl && nr <= qr) return st[node];
    int nm = (nr + nl) >> 1;
    return max(query(2 * node,     nl, nm, ql, qr),
               query(2 * node + 1, nm, nr, ql, qr));
}

void aggiorna(int P, int X) {
    update(1, 0, sz, P, X);
}

int massimo(int L, int R) {
    return query(1, 0, sz, L, R + 1);
}