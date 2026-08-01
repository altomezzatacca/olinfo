#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, P;
    cin >> N >> P;
    
    vector<array<int, 3>> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i][0] >> S[i][1] >> S[i][2];
    }
	int ans = 0;

	int S_1 = S[0][0] + S[0][1] + S[0][2];
	int S_2 = S[1][0] + S[1][1] + S[1][2] + P*100;
	ans = S_2 - S_1 + 1;
	if (ans<0) ans=0;

    cout << ans << endl; // print the result
    
    return 0;
}
