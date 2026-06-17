#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B; cin >> A >> B;
        if(A < 33 || A > 53 || B > 52 ||
           B < 11 * ceil(1.0 * (A - 33) / 11) || 
           (A == 44 && B < 22)) {
            cout << -1 << " " << -1 << "\n";
            continue;
        }
        vector<pair<int, int>> V (3, {0, 0});
        if (A > 33  || B > 30) V.push_back({0, 0});
        if (A >= 44 || B > 41) V.push_back({0, 0});
        V[0].first = 11; V[1].first = 11;
        V.back().first = 11; A -= 33;
        if (A > 0 || B > 30) {
            int x = min(A, 10), y = 11;
            A -= x; B -= y;
            V[2] = {x, y};
        }
        if (A > 0 || B > 30){
            int x = min(A, 10), y = 11;
            A -= x; B -= y;
            V[3] = {x, y};
        }
        for(int i = 0; i < 2; i++){
            int b = min(B, 10);
            V[i].second = b; B -= b;
        }
        int b = min(B, 10);
        V.back().second = b; B -= b;
        for(int i = 0; i < V.size(); i++)
            cout << V[i].first << " " << V[i].second << "\n";
    }
    return 0;
}