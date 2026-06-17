#include<bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int N; cin >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i){
        int x; cin >> x;
        ans += x;
    }
    ans += 2 * N;
    cout << ans << endl;
    return 0;
}
