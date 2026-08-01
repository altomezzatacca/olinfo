#include <bits/stdc++.h>
using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B;
        cin >> A >> B;
        string X = "";
        int t = A + B;
        int tt = 0, ix = 1;
        while(t > tt){
            tt += ix;
            ix++;
        } ix--;
        if(t != tt) {
            X = "IMPOSSIBILE";
            cout << "Case #" << test << ": " << X << endl;
            continue;
        }
        while(ix){
            if(A >= ix){
                X = "1" + X;
                A -= ix;
            }
            else if(B >= ix){
                X = "2" + X;
                B -= ix;
            }
            ix--;
        }
        cout << "Case #" << test << ": " << X << endl;
    }
    return 0;
}
