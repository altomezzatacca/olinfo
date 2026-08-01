#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
	int N, M, K, A, B;
	cin >> N >> M >> K >> A >> B;
	vector<vector<int>> V(N, vector<int> (M)), pref(N, vector<int> (M));
	for(int i = 0, x, y; i < K; V[x][y]++, i++)
		cin >> x >> y;
	pref[0][0] = V[0][0];
	for(int i = 1; i < N; i++)
		pref[i][0] = V[i][0] + pref[i - 1][0];
	for(int i = 1; i < M; i++)
		pref[0][i] = V[0][i] + pref[0][i - 1];
	for(int i = 1; i < N; i++)
		for(int j = 1; j < M; j++)
			pref[i][j] = V[i][j] +
						 pref[i - 1][j] +
						 pref[i][j - 1] -
						 pref[i - 1][j - 1];
	int ans = pref[A - 1][B - 1];
	for(int i = A; i < N; i++)
		ans = min(ans, pref[i][B - 1] - pref[i - A][B - 1]);
	for(int i = B; i < M; i++)
		ans = min(ans, pref[A - 1][i] - pref[A - 1][i - B]);
	for(int i = A; i < N; i++)
		for(int j = B; j < M; j++)
			ans = min(ans, pref[i][j] + pref[i - A][j - B] - pref[i - A][j] - pref[i][j - B]);
	cout << "Case #" << t << ": " << ans << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
		solve(t);
	return 0;
}