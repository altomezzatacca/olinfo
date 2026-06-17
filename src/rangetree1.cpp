#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value = 0; bool has_update = false;
    void propagate(Node &l, Node &r, int sz){
        if(!has_update) return;
        l.value = sz / 2 - l.value; //flip
        r.value = sz / 2 - r.value;
        l.has_update = !l.has_update;
        r.has_update = !r.has_update;
        has_update = false;
    }
};

struct SegTree{
    int sz;
    vector<Node> tree;
    SegTree(int N){ //costruttore
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2 * sz);
    }
    int query(int node, int nl, int nr, int ql, int qr){
        if(qr <= nl || nr <= ql) return 0; //il nodo è fuori dall'intervallo della query
        if(ql <= nl && nr <= qr) return tree[node].value; //il nodo è completamente nella query
        tree[node].propagate(tree[2 * node], tree[2 * node + 1], nr - nl);
        int nm = (nr + nl) / 2;
        return query(2 * node,     nl, nm, ql, qr) +
               query(2 * node + 1, nm, nr, ql, qr);
    }
    void update(int node, int nl, int nr, int ql, int qr){
        if(qr <= nl || nr <= ql) return;
        if(ql <= nl && nr <= qr) {
            tree[node].value = nr - nl - tree[node].value;
            tree[node].has_update = !tree[node].has_update;
            return;
        }
        tree[node].propagate(tree[2 * node], tree[2 * node + 1], nr - nl);
        int nm = (nr + nl) / 2;
        update(2 * node,     nl, nm, ql, qr);
        update(2 * node + 1, nm, nr, ql, qr);
        tree[node].value = tree[2 * node].value + tree[2 * node + 1].value;
    }
};

int main(){
    int N, Q; cin >> N >> Q;
    SegTree st(N);
    while(Q--){
        int type, l, r; cin >> type >> l >> r;
        r++;
        if(type == 0) //update
            st.update(1, 0, st.sz, l, r);
        else  //query
            cout << st.query(1, 0, st.sz, l, r) << "\n";
    }

    return 0;
}