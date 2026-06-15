#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
static int N, m;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct treap{
    int v, p, sz;
    treap *L, *R;
    treap() {} // costruttore vuoto per permettermi prealloc
    treap(int x){
        L = R = nullptr;
        v = x;
        p = rng();
        sz = 1;
    }
    treap *join(treap *_L, treap *_R){
        L = _L;
        R = _R;
        sz = 1;
        if(L) sz += L->sz;
        if(R) sz += R->sz;
        return this;
    }
};

inline int t_sz(treap* T){
    if(T) return T->sz;
    return 0;
}

inline pair<treap*, treap*> split(treap *T, int x){
    if(!T) return {nullptr, nullptr};
    if(t_sz(T->L) < x){
        auto [RL, RR] = split(T->R, x - t_sz(T->L) - 1);
        return {T->join(T->L, RL), RR};
    } else {
        auto [LL, LR] = split(T->L, x);
        return {LL, T->join(LR, T->R)};
    }
}

inline treap *merge(treap *L, treap *R){
    if(!L) return R;
    if(!R) return L;
    if(L->p > R->p){
        return L->join(L->L, merge(L->R, R));
    } else {
        return R->join(merge(L, R->L), R->R);
    }
}

treap *prealloc;

inline treap *insert(treap *T, int x, int i){
    auto [L, R] = split(T, i);
    treap *X = prealloc++;
    *X = treap(x);
    return merge(L, merge(X, R));
}

inline treap *erase(treap *T, int i){
    auto [L, MR] = split(T, i);
    auto [M, R] = split(MR, 1);
    return merge(L, R);
}

inline int qfind(treap *&T, int i){ // valore in posizione i-esima
    auto [L, MR] = split(T, i); // smonto l'albero
    auto [M, R] = split(MR, 1); // trovo il valore
    int ans = M->v;
    T = merge(L, merge(M, R)); // rimonto l'albero
    return ans;
}

inline void qswap(treap *&T, int i, int j){
    int x = qfind(T, i);
    T = erase(T, i);
    T = insert(T, x, j);
}

inline void heapify(treap *T){
    treap *mx = T; // max
    if(T->L && T->L->p > T->p) mx = T->L;
    if(T->R && T->R->p > T->p) mx = T->L; // mx o T dopo il > ?
    if(mx == T) return;
    swap(T->p, mx->p);
    heapify(mx);
}

inline treap *build(int l, int r){
    if (l == r) return nullptr;
    int mid = (l + r) >> 1;
    treap *current = prealloc++;
    *current = treap(mid);
    current->join(build(l, mid), build(mid + 1, r));
    heapify(current);
    return current;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> N >> m;
    prealloc = new treap[N + m]; // prealloco spazio per N nodi iniziali ed eventuali M nodi
    treap *T = build(0, N);
    for(int q = 0, i, j; q < m; q++){
        char c; cin >> c;
        if(c == 'c'){
            cin >> i;
            cout << qfind(T, i) << " ";
        } else { // c == 's'
            cin >> i >> j;
            qswap(T, i, j);
        }
    }
}