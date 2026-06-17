#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; cin >> N;
    vector<char> L(N);
    int available = 26, space = 0;
    for (int i = 0; i < N; i++){
        cin >> L[i];
        if(L[i] != '_') available--;
        else space++;
    }
    int ans = 1;
    for(;space--;)
        ans *= available--;
    cout << ans << endl; // print the result
    return 0;
}
