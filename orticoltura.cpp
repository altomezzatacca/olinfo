#include <bits/stdc++.h>
using namespace std;
struct seme{
	int x;
	int p;
	int val;
};

void posiziona(int D, int T);

void budget(int B);

bool comp(seme x, seme y){
	return x.val<y.val;
}

void irriga(int C, int N, vector<int>& X, vector<int>& P){
    
	vector<seme> S(N);
	vector<pair<int, int>> irr; //.first --> x .second--> p
	for(int i=0; i<N; i++) {
		S[i].x = X[i];
		S[i].p = P[i];
		S[i].val = X[i] - P[i];
	}
	sort(S.begin(), S.end(), comp);
	
	irr.push_back({S[0].x, S[0].p});
	int ans = C + S[0].p;
	
	for(int i = 1; i < N; i++){
		int c = max( (S[i].x - irr.back().first + S[i].p - irr.back().second) / 2, 0);
		if (c < C + S[i].p){
			irr.back().first += c;
			irr.back().second += c;
			ans += c;
		} else{
			irr.push_back({S[i].x, S[i].p});
			ans += C + S[i].p;
		}
	}
	
	for(auto [x, y]: irr){
		posiziona(x, y);
	}
	budget(ans);
    return;
}