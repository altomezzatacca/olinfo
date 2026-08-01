#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<map<int, int>> dpb; 	// dpb[i][j] --> piani controllabili con i vite e j mosse
vector<map<int, int>> dp;	/*	la chiave di dp[i][j] contiene il numero di piani controllabili con i vite e j mosse;
								il valore assegnato alla chiave è invece la "query", ovvero il miglior piano da controllare nella situazione attuale */

bool attack(int);

void init(int n, int k) {
    N = n; K = k;
    dpb.resize(k + 1); dp.resize(k + 1);
    for(int i = 2; i <= k; i++){ // i vite, partiamo da 2 perchè tanto con i = 1 abbiamo il caso base (ed è il più dispendioso [ O(N) ])
    	for(int j = 1; ; j++){ // j mosse
    		int macs, q;
			if (i >= j) {
				q = (1 << (j - 1)) - 1;
				macs = (1 << j) - 1;
    		}else{
				q = (i == 2 ? j - 1 : dpb[i - 1][j - 1]);
				macs = 1 + dpb[i][j - 1] + q;
    		}
			dpb[i][j] = macs;
    		dp[i][macs] = q;
    		if (macs >= n) break;
		}
	}
}

inline static int solve (int l, int r, int k){
	if(l==r) return l; // risposta univoca trovata
	if (k==1){ // caso base (per identificare il pokemon con una vita è necessario farli uno a uno)
		while(l<r && attack(l)) l++;
		return l;
	} else {
		int n = r - l;
		auto it = dp[k].lower_bound(n); // il lower_bound su map è sulla chiave e non sul valore, questo ci permette di operare in O(log N) ad ogni ricerca
		int q = l + min(it->second, n - 1); //dato che potrebbe superare n, controlliamo n - 1 (invece di n per chiare ragioni)
		if(attack(q)){
			return solve(q + 1, r, k);
		} else {
			return solve(l, q, k - 1);
		}
	}
}

int new_pokemon() {
	return solve(0, N, K);
}