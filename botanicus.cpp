#include <bits/stdc++.h>
using namespace std;
const int MAXN=1500000;

void dfs(vector<vector<int>> &adj, vector<int> &H, vector<int> &max_H, int u){
	max_H[u]=H[u];
	for(auto v: adj[u]){
		H[v]=H[u]+1;
		dfs(adj, H, max_H, v);
		max_H[u]=max(max_H[u], max_H[v]);
	}
}

int pota(int N, vector<int> P){
	
	int ans=0;
	vector<vector<int>> adj(N);
	for(int i=1; i<N; i++) adj[P[i]].push_back(i);
	
	vector<int> H(N), max_H(N);
	H[0]=0;
	
	dfs(adj, H, max_H, 0);
	
	int maxH = *max_element(max_H.begin(), max_H.end());
	vector<int> sweep(maxH+2, 0);
	
	for(int i=0; i<N; i++){
		sweep[H[i]]++;
		sweep[max_H[i]+1]--;
	}
	
	int val=0;
	for(int i=0; i<=maxH; i++){
		val+=sweep[i];
		ans=max(ans, val);
	}
	
	return N-ans;
} 

/*
struct nodo{
	int padre;
	int h;
	bool foglia=1;
	set<int> al;
	set<int> son;
};

void alinsert(vector<nodo> &V, int ix, int h){
	V[ix].al.insert(h);
	V[ix].son.insert(ix);
	if(ix!=0) alinsert(V, V[ix].padre, h);
}

bool comp(nodo &a, nodo &b){
	return a.h<b.h;
}

bool comp2(nodo &a, int x){
	return a.h<x;
}

int pota(int N, vector<int> P) {
    vector<nodo> V(N);
    V[0]={-1, 0, 0, {0}, {}};
    for(int i=1; i<N; i++){
    	V[i].padre=P[i];
    	V[i].h=V[P[i]].h+1;
    	V[i].al.insert(V[i].h);
    	alinsert(V, V[i].padre, V[i].h);
	}
	for(int i=1; i<N; i++) V[P[i]].foglia=0;
	sort(V.begin(), V.end(), comp);
	int mini=MAXN, maxH=V[N-1].h;
	vector<nodo> V1;
	for(int i=0; i<=maxH; i++){
		V1=V;
		int x=0;
		int h=(*lower_bound(V.begin(), V.end(), i, comp2)).h;
		for(int i=1; i<N; i++){
			if(V[])
		}
		mini=min(mini, x);
	}
	return x;
}*/ // ma wtf stavo facendo, lo terrò come ricordo