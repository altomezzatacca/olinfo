#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N; cin >> N;
        vector<long long> P(N), C(N), pref(N);
        for (int i = 0; i < N; ++i)
            cin >> P[i];
        for (int i = 0; i < N; pref[i] = (i == 0 ? C[i] : min(pref[i - 1], C[i])), i++)
            cin >> C[i];
        long long ans = 0;
        for(int i = 0; i < N; i++)
            ans += pref[i] * P[i];
        cout << "Case #" << test << ": ";
        cout << ans << endl;
    }
    return 0;
}