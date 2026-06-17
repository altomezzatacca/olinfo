#include <bits/stdc++.h>
using namespace std;

int gioca (int N, int K, vector<vector<int>> V) {
	int ris=0;
    
    deque<deque<int>> M(N);
    for(int i=0; i<N; i++){
    	for(int j=0; j<K; j++){
    		M[i].push_back(V[i][j]);
		}
	}
    
	for(int i=0; i<N; i++){
		deque<int> temp;
		int max=-1;
		for(int j=0; j<K; j++){
			if(M[i][j]>max){
				max=M[i][j];
				temp.push_back(max);
			}
		}
		M[i]=temp;
	}
	vector<bool> stat(N, 1);
	priority_queue<pair<int, int>> pq;
	for (int i=0; i<N; i++) pq.push({M[i].back(), i});
    while(!pq.empty()){
    	auto [val, i] = pq.top();
        pq.pop();

        if (!stat[i]) continue;

        while (!pq.empty() && pq.top().first==val) {
            auto [a, j] = pq.top();
			pq.pop();
            if (stat[j]) {
                M[j].pop_back();
                if (M[j].empty()) stat[j] = false;
				else pq.push({M[j].back(), j});
            }
        }

        M[i].pop_back();
        if (M[i].empty()) stat[i] = false;
        else pq.push({M[i].back(), i});

        ris++; 
	}
    
	return ris;
}