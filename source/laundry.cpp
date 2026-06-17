#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, C, W;
    cin >> N >> C >> W;
    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i]; 
    sort(T.rbegin(), T.rend());
    int i = 0;
    int ans = 0;
    int washes = 0;
    vector<int> dry;
	while(N - i >= C) {
		washes++;
		dry.push_back(T[i]);
		i += C;
	}
	if(i < N){
		washes++;
		dry.push_back(T[i]);
	}
	
	ans += W;
	for(int k = 0; k < washes - 1; k++){
		ans += max(W, dry[k]);
	}
	ans += dry[washes - 1];

    cout << ans << endl;

    return 0;
}