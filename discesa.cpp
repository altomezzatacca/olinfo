#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int A; cin >> A;
    vector<vector<int>> V(A);
    for(int i = 0; i < A; i++){
        V[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> V[i][j];
        }
    }
    for(int i = A - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            V[i][j] += max(V[i + 1][j], V[i + 1][j + 1]);
        }
    }
    cout << V[0][0];
    return 0;
}