#include <iostream>
#include <string>
using namespace std;

void solve(int t) {
    int K;
    cin >> K;
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int tot = A + 2 * B + 3 * C + 4 * D;
    while(K--){
        if(A > 0){
            A--;
            tot += 3;
        } else if (B > 0){
            B--;
            tot += 2;
        } else if (C > 0){
            C--;
            tot ++;
        } else D--;
    }
    cout << "Case #" << t << ": " << tot << "\n";
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
