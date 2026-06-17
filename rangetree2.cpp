#include <bits/stdc++.h>
using namespace std;

struct Nodo {
	int c[3];
	int lazy;
};

vector <Nodo> tree;

void build(int nodo, int l, int r){
	if (l==r) tree[nodo] = {1, 0, 0, 0};
	else {
		int m=(l+r)/2;
		build (2*nodo, l, m);
		build (2*nodo+1, m+1, r);
		tree[nodo].c[0]=tree[2*nodo].c[0]+tree[2*nodo+1].c[0];
	}
}

void lazy(int nodo, int l, int r){
	if (tree[nodo].lazy){
		int x=tree[nodo].lazy%3;
		while(x--) {
			int temp = tree[nodo].c[2];
			tree[nodo].c[2] = tree[nodo].c[1];
        	tree[nodo].c[1] = tree[nodo].c[0];
        	tree[nodo].c[0] = temp;
		}
		if (l!=r) {
			tree[2 * nodo].lazy = (tree[2 * nodo].lazy + tree[nodo].lazy) % 3;
            tree[2 * nodo + 1].lazy = (tree[2 * nodo + 1].lazy + tree[nodo].lazy) % 3;
		}
		tree[nodo].lazy=0;
	}
}

void update(int nodo, int l, int r, int ql, int qr){
	lazy(nodo, l, r);
	if (qr<l || r<ql) return;
	if (ql<=l && r<=qr) {
		tree[nodo].lazy = (tree[nodo].lazy + 1)%3;
		lazy(nodo, l, r);
	}
	else {
		int m=(l+r)/2;
		update(2*nodo, l, m, ql, qr);
		update(2*nodo+1, m+1, r, ql, qr);
		for (int i=0; i<3; i++) tree[nodo].c[i] = tree[2*nodo].c[i] + tree[2*nodo+1].c[i];
	}
}

void mult (int nodo, int l, int r, int ql, int qr, int &s){
	lazy(nodo, l, r);
	if (qr<l || r<ql) return;
	if (ql<=l && r<=qr) s+=tree[nodo].c[0];
	else {
		int m=(l+r)/2;
		mult (2*nodo, l, m, ql, qr, s);
		mult (2*nodo+1, m+1, r, ql, qr, s);	
	}
} 

int main(){

	ifstream cin("input.txt");
    ofstream cout("output.txt");
	
	int N, Q; 
	cin >> N >> Q;
	tree.resize(4*N);
	build(1, 0, N-1);
	
	for (int i=0; i<Q; i++){
		int q, a, b;
		cin >> q >> a >> b;
		if (q==0) update(1, 0, N-1, a, b);
		else {
			int s=0;
			mult(1, 0, N-1, a, b, s);
			cout<<s<<"\n";
		}
	}

	return 0;
}
