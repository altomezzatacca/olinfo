#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int t) {
    int N;
    cin >> N;
    vector<int> S(N, 0);
    for(int i = 0; i < N; i++) cin >> S[i];
    int risposta = 0;
    for(int i = 0; i < N; i++){
        int cur = 0;
        for(int j = 0; j < N; j++){
            if(S[j] == 1 || i == j) cur++;
            else{
                risposta = max(risposta, cur);
                cur = 0;
            }
        }
        risposta = max(risposta, cur);
    }
    cout << "Case #" << t << ": " << risposta << "\n";
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