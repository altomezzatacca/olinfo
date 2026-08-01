#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N; cin >> N;
        vector<int> W(N);
        for (int i = 0; i < N; i++)
            cin >> W[i];

        int K = 0;
		int m = 0;
    for(int i = 0; i < N; i++){
      int x = 0, y = 0;
      m = 0;
        for(int j = i; j < N; j++){
        	if(W[j]==1)
        		x++;
			else
				y++;
			if(max(x, y) >= 4 && abs(x-y) > 1){
				m++;
				x = y = 0;
			}
		}
		K = max(m, K);
	}
        cout << K << "\n";
    }

    return 0;
}