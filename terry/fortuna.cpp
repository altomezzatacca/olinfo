#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;

void solve(int t) {
    int N;
    cin >> N;
    vector<int> V(N), G(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> G[i];
    }
    int ans = 1e9;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j++)
            sum += V[(i + j) % N] * G[j];
        ans = min(ans, sum);
    }
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