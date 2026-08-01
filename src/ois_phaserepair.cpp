#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    set<int> S;
    for (int i = 0; i < N; ++i){
    	int x; cin >> x;
    	S.insert(x);
	}
	vector<int> V;
	for(auto x: S)
		V.push_back(x);
	int n = V.size();
	V.push_back(*S.begin());
	vector<int> dist(n);
	for(int i = 0; i < n - 1; i++){
		dist[i] = M + V[i] - V[i+1];
	}
	dist[n - 1] = V[n - 1] - V[n];
	
	int ix = 0;
    for(int i = 1; i < n; i++)
    	if(dist[i] < dist[ix]) ix = i;
    vector<int> A;
    int ans = 0;
    for(int i = V[ix + 1]; i != V[ix]; i++, i %= M){
    	A.push_back(i);
    	ans++;
    }
    cout << ans <<"\n";
    for(auto u: A) cout << u << " ";

    return 0;
}
