#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M; cin >> N >> M;
    map<int, int> m;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        m[x] = i;
    }
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        m[x]--; m[y]++;
    }
    int best = 1;
    for(int i = 2; i <= N; i++)
        if(m[i] < m[best]) best = i;
    cout << best;
    return 0;
}