#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; t++){
        int N; cin >> N;
        vector<int> V(N), G(N);
        for(int i = 0; i < N; i++)
            cin >> V[i];
        for(int i = 0; i < N; i++)
            cin >> G[i];
        vector<bool> possible(N);
        possible[0] = 1;
        for(int i = 0; i < N; i++){
            int best = 0;
            for(int j = 0; j <= i; j++)
                if(possible[j])
                    best = max(best, V[j] + G[j] * (i - j));
            if(best >= V[i]) possible[i] = 1;
        }
        int ans = 0;
        for(int i = 0; i < N; i++)
            if(possible[i])
                ans = max(ans, V[i] + G[i] * (N - i));
        cout << "Case #" << t << ": " << ans << endl;
    }
}