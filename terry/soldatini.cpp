#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int t) {
    int N;
    cin >> N;
    string S;
    vector<int> gruppi;
    cin >> S;
    int risposta = 0;
    int cur = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == '1') cur++;
        else {
            if(cur != 0) gruppi.emplace_back(cur);
            cur = 0;
            gruppi.emplace_back(0);
        }
    }
    if(cur != 0) gruppi.emplace_back(cur);
    if(gruppi.size() <= 3) risposta = N;
    else {
        int n = gruppi.size();
        for(int i = 1; i < n - 1; i++)
            if(gruppi[i] == 0)
                risposta = max(risposta, gruppi[i - 1] + 1 + gruppi[i + 1]);
        if(gruppi[0] == 0) risposta = max(risposta, gruppi[1] + 1);
        if(gruppi[n - 1] == 0) risposta = max(risposta, gruppi[n - 2] + 1);
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