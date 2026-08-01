#include <bits/stdc++.h>
using namespace std;
vector<int> vx = {0, 0, -1, 1},
			vy = {1, -1, 0, 0};

void solve(int t){
	int P, N, M; cin >> P >> N >> M;
	vector<map<int, bool>> is_broken(N + 1);
	vector<map<int, int >> dist(N + 1);
	for(int i = 0; i < P; i++){
		int x, y; cin >> x >> y;
		is_broken[x][y] = 1;
		dist[x][y] = 1e9;
	}
	queue<tuple<int, int, int>> q;
	for(int i = 1; i <= N; i++)
		for(auto [j, b]: is_broken[i])
			for(int k = 0; b && k < 4; k++){
				int nx = i + vx[k], ny = j + vy[k];
				if(nx >= 1 && nx <= N && ny >= 1 && ny <= M)
					if(!is_broken[nx][ny])
						q.emplace(0, nx, ny);
			}
	while(!q.empty()){
		auto [d, x, y] = q.front(); q.pop();
		if(d > dist[x][y]) continue;
		for(int k = 0; k < 4; k++){
			int nx = x + vx[k], ny = y + vy[k];
			if(nx >= 1 && nx <= N && ny >= 1 && ny <= M && is_broken[nx][ny] && dist[nx][ny] > d + 1)
				q.emplace(dist[nx][ny] = d + 1, nx, ny);
		}
	}
	int ans = 1e9;
	for(int x = 1; x <= N; x++)
		for(auto [y, d]: is_broken[x]){
			if(dist[x][y] == 0) continue;
			bool center = 1;
			for(int k = 0; k < 4 && center; k++){
				int nx = x + vx[k], ny = y + vy[k];
				if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
				if(dist[x][y] < dist[nx][ny])
					center = 0;
			}
			if(center)
				ans = min(ans, dist[x][y]);
		}
	cout << "Case #" << t << ": ";
	cout << ans - 1 << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for (int test = 1; test <= T; test++)
        solve(test);
    return 0;
}