#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        vector<int> H(N);
        for (int i = 0; i < N; ++i)
            cin >> H[i];
        int x = 0;
        vector<int> P(N);
        for(int i = 1; i < N - 1; i++){
            if(H[i - 1] > H[i] || H[i + 1] > H[i]) continue;
            int k = min(H[i] - H[i - 1], H[i] - H[i + 1]);
            P[i] = k;
            if(k > P[x])
                x = i;
        }
        cout << "Case #" << test << ": ";
        cout << (x == 0 ? -1 : x) << endl;
    }

    return 0;
}
