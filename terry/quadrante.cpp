#include <bits/stdc++.h>
using namespace std;

bool possible(vector<array<int, 2>> V){
    int N = V.size();
    sort(begin(V), end(V));
    for(int i = 1; i < N; i++)
        if(V[i][1] < V[i - 1][1])
            return 0;
    return 1;
}

void solve(int t) {
    int N; cin >> N;
    vector<array<int, 2>> V(N);
    for(int i = 0; i < N; i++)
        cin >> V[i][0] >> V[i][1];
    int l = 0, r = N;
    while(r - l > 1){
        int m = (l + r) >> 1;
        vector<array<int, 2>> temp;
        for(int i = 0; i <= m; i++)
            temp.emplace_back(V[i]);
        bool b = possible(temp);
        if(b) l = m;
        else r = m;
    }
    cout << "Case #" << t << ": " << r << "\n";
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