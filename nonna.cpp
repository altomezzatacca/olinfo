#include <bits/stdc++.h>
#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000
using namespace std;

int mangia(int N, int K, int P[], int _min) {
    int s = K + _min;
	vector<bool> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    	for (int j = s - P[i]; j >= 0; j--)
    		if(dp[j]) dp[j + P[i]] = 1;
	for (int i = K; i <= s; i++)
		if(dp[i]) return i;
}

int P[MAXN];

int main() {
    int N, K, i, _min = MAXP;
    freopen("input.txt",  "r", stdin );
    freopen("output.txt", "w", stdout);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> P[i];
        _min = min(_min, P[i]);
    }
    cout << mangia(N, K, P, _min) << "\n";

    return 0;
}