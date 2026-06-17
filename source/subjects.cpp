// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<vector<int>> S(N);
    vector<int> K(N);
    for (int j = 0; j < N; ++j) {
        cin >> K[j];
        S[j].resize(K[j]);
        for (int i = 0; i < K[j]; ++i)
            cin >> S[j][i];
    }

    int P = 0;
    set<pair<int, int>> ans;

	for (int i=1; i<M; i++) {
        for (int j=i+1; j<=M; j++) {
            ans.insert({i, j});
        }
    }
	
	for (int j=0; j<N; j++){
		for(int i=0; i<K[j]-1; i++){
			for(int k=i+1; k<=K[j]; k++){
				int a=min(S[j][i], S[j][k]);
                int b=max(S[j][i], S[j][k]);
                ans.erase({a, b});
			}
		}
	}

    cout << ans.size() << "\n";
    for (auto j : ans) {
        cout << j.first << " " << j.second << "\n";
    }

    return 0;
}
