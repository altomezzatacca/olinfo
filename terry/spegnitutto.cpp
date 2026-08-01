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
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        int ris = 0;
        for(int i = 0; i < N - 1; i++){
            if(A[i] == 1){
                ris++;
                A[i] = 0;
                if(A[i + 1] == 1)
                    A[i + 1] = 0;
            }
        }
        if(A[N - 1]) ris++;
        cout << "Case #" << test << ": ";
        cout << ris << endl;
    }
    return 0;
}