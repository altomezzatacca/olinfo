#include <bits/stdc++.h>
using namespace std;

vector<int> verifica(int N, vector<int> T) {
	vector<int> V;
	deque<pair<int, int>> D;
	for (int i=0; i<N; i++){
		D.push_back({T[i], i});
	}
	sort(D.begin(), D.end());
	V.push_back(D[0].second);
	int r=D[0].second, l=D[0].second;
	int t=0;
	D.pop_front();
	bool possible=1;
	while(!D.empty() && possible){
		if(D[0].second>=l && D[0].second<=r) {
			D.pop_front();
			continue;
		}
		if(D[0].second>r){
			while(r<D[0].second && t<D[0].first){
				t++; r++;
				if (r!=D[0].second) V.push_back(r);
			}
			if(D[0].second==r){
				V.push_back(D[0].second);
				D.pop_front();
			} else possible=0;
		} else if(D[0].second<l){
			while(l>D[0].second && t<D[0].first){
				t++; l--;
				if (l!=D[0].second) V.push_back(l);
			}
			if(D[0].second==l){
				V.push_back(D[0].second);
				D.pop_front();
			} else possible=0;
		}
	}
	if (!possible) return{};
	else return V;
}