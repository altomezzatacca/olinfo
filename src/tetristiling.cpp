#include <bits/stdc++.h>
using namespace std;

void base (int n, int &pieces, vector<vector<int>> &T){
	switch(n){
		case 1:
			pieces = 0;
			T = {{0}};
			break;
		case 2:
			pieces = 0;
			T = {{0, 0}, {0, 0}};
			break;
		case 3:
			pieces = 1;
			T = {{0, 0, 1}, {0, 1, 1}, {0, 0, 1}};
			break;
		case 4:
			pieces = 4;
			T = {{1, 2, 2, 2}, {1, 1, 2, 4}, {1, 3, 4, 4}, {3, 3, 3, 4}};
			break;
		case 7:
			pieces = 12;
			T = {{0, 1, 10, 10, 9, 9, 9}, {2, 1, 1, 10, 10, 9, 8}, {2, 2, 1, 11, 11, 8, 8}, {2, 3, 11, 11, 12, 8, 7}, {3, 3, 5, 12, 12, 7, 7}, {3, 4, 5, 5, 12, 6, 7}, {4, 4, 4, 5, 6, 6, 6}};
			break;
		case 10:
			pieces = 25;
			T = {{1, 2, 2, 2, 3, 3, 4, 4, 5, 5}, {1, 1, 2, 3, 3, 4, 4, 5, 5, 6}, {1, 23, 23, 23, 24, 24, 25, 25, 6, 6}, {16, 16, 23, 24, 24, 25, 25, 7, 7, 6}, {17, 16, 16, 20, 22, 22, 22, 21, 7, 7}, {17, 17, 18, 20, 20, 22, 21, 21, 8, 8}, {17, 18, 18, 19, 20, 12, 21, 8, 8, 9}, {15, 18, 19, 19, 19, 12, 12, 11, 9, 9}, {15, 15, 14, 13, 13, 12, 11, 11, 10, 9}, {15, 14, 14, 14, 13, 13, 11, 10, 10, 10}};
			break;
	}
}

void tadd(int &n, int &pieces, vector<vector<int>> &T){
	for(int i = 0; i < 4; i++) T.push_back({});
	int temp = n, i1 = 0;
	while(temp >= 4){
		T[i1].insert(T[i1].end(), {pieces + 1, pieces + 2, pieces + 2, pieces + 2});
		T[i1 + 1].insert(T[i1 + 1].end(), {pieces + 1, pieces + 1, pieces + 2, pieces + 4});
		T[i1 + 2].insert(T[i1 + 2].end(), {pieces + 1, pieces + 3, pieces + 4, pieces + 4});
		T[i1 + 3].insert(T[i1 + 3].end(), {pieces + 3, pieces + 3, pieces + 3, pieces + 4});
		temp -= 4; i1 += 4; pieces += 4;
	}
	temp = n;
	while(temp >= 4){
		T[n].insert(T[n].end(), {pieces + 1, pieces + 2, pieces + 2, pieces + 2});
		T[n + 1].insert(T[n + 1].end(), {pieces + 1, pieces + 1, pieces + 2, pieces + 4});
		T[n + 2].insert(T[n + 2].end(), {pieces + 1, pieces + 3, pieces + 4, pieces + 4});
		T[n + 3].insert(T[n + 3].end(), {pieces + 3, pieces + 3, pieces + 3, pieces + 4});
		temp -= 4; pieces += 4;
	}
	switch(n % 4){
		case 1:
			T[n - 1].insert(T[n - 1].end(), {pieces + 1, pieces + 2, pieces + 2, pieces + 2});
			T[n + 0].insert(T[n + 0].end(), {pieces + 3, pieces + 1, pieces + 1, pieces + 2, pieces + 4});
			T[n + 1].insert(T[n + 1].end(), {pieces + 3, pieces + 3, pieces + 1, pieces + 4, pieces + 4});
			T[n + 2].insert(T[n + 2].end(), {pieces + 3, pieces + 5, pieces + 5, pieces + 6, pieces + 4});
			T[n + 3].insert(T[n + 3].end(), {pieces + 5, pieces + 5, pieces + 6, pieces + 6, pieces + 6});
			pieces += 6;
			break;
		case 2:
			T[n - 2].insert(T[n - 2].end(), {pieces + 1, pieces + 2, pieces + 2, pieces + 2});
			T[n - 1].insert(T[n - 1].end(), {pieces + 1, pieces + 1, pieces + 2, pieces + 3});
			T[n + 0].insert(T[n + 0].end(), {pieces + 7, pieces + 8, pieces + 8, pieces + 1, pieces + 3, pieces + 3});
			T[n + 1].insert(T[n + 1].end(), {pieces + 7, pieces + 7, pieces + 8, pieces + 8, pieces + 3, pieces + 4});
			T[n + 2].insert(T[n + 2].end(), {pieces + 7, pieces + 6, pieces + 6, pieces + 5, pieces + 4, pieces + 4});
			T[n + 3].insert(T[n + 3].end(), {pieces + 6, pieces + 6, pieces + 5, pieces + 5, pieces + 5, pieces + 4});
			pieces += 8;
			break;
		case 3:
			T[n - 3].insert(T[n - 3].end(), {pieces + 1, pieces + 1, pieces + 1, pieces + 2});
			T[n - 2].insert(T[n - 2].end(), {pieces + 3, pieces + 1, pieces + 2, pieces + 2});
			T[n - 1].insert(T[n - 1].end(), {pieces + 3, pieces + 3, pieces + 10, pieces + 2});
			T[n + 0].insert(T[n + 0].end(), {pieces + 8, pieces + 8, pieces + 8, pieces + 3, pieces + 10, pieces + 10, pieces + 4});
			T[n + 1].insert(T[n + 1].end(), {pieces + 7, pieces + 8, pieces + 9, pieces + 9, pieces + 10, pieces + 4, pieces + 4});
			T[n + 2].insert(T[n + 2].end(), {pieces + 7, pieces + 7, pieces + 6, pieces + 9, pieces + 9, pieces + 5, pieces + 4});
			T[n + 3].insert(T[n + 3].end(), {pieces + 7, pieces + 6, pieces + 6, pieces + 6, pieces + 5, pieces + 5, pieces + 5});
			pieces += 10;
			break;
		case 0:
			T[n].insert(T[n].end(), {pieces + 1, pieces + 2, pieces + 2, pieces + 2});
			T[n + 1].insert(T[n + 1].end(), {pieces + 1, pieces + 1, pieces + 2, pieces + 4});
			T[n + 2].insert(T[n + 2].end(), {pieces + 1, pieces + 3, pieces + 4, pieces + 4});
			T[n + 3].insert(T[n + 3].end(), {pieces + 3, pieces + 3, pieces + 3, pieces + 4});
			pieces += 4;
			break;
	}
	n += 4;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N; cin >> N; int n = N;

    int pieces = 0;
    vector<vector<int>> T;
    
    while(n > 4 && n != 7 && n != 10) n -= 4;
    base(n, pieces, T);
    while(n < N){
    	tadd(n, pieces, T);
	}
    
    cout << pieces << endl;
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i)
            cout << T[j][i] << " ";
        cout << endl;
    }

    return 0;
}
