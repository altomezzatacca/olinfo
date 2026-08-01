#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M, K;
    cin >> N >> M >> K;
    string P;
    cin >> P;

    vector<vector<bool>> visited(N, vector<bool> (M, 0));
    vector<pair<int, int>> path = {{0, 0}};
    vector<vector<bool>> bomb(N, vector<bool> (M, 0));
    visited[0][0] = 1;
    int n = P.size();
    int row = 0, column = 0;
    for(int i = 0; i < n; i++){
    	switch(P[i]){
    		case 'D':
    			row++;
    			break;
    		case 'U':
    			row--;
    			break;
    		case 'L':
    			column--;
    			break;
    		case 'R':
    			column++;
    			break;
		}
		if(!visited[row][column]){
			visited[row][column] = 1;
			path.emplace_back(row, column);
		}
	}
    int free = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(!visited[i][j]){
				free++;
				bomb[i][j] = 1;
			}
		}
	}
	int bombs = K - free;
	int subemelaradjo = path.size();
	for(int i = 0; i < bombs; i++){
		auto [ow, col] = path[subemelaradjo - 1 - i];
		bomb[ow][col] = 1;
	}
	
	row = 0; column = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
    	switch(P[i]){
    		case 'D':
    			row++;
    			break;
    		case 'U':
    			row--;
    			break;
    		case 'L':
    			column--;
    			break;
    		case 'R':
    			column++;
    			break;
		}
		if(!bomb[row][column]){
			ans++;
		} else break;
	}

    cout << ans << endl;

    return 0;
}