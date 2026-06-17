// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    int steps = 0;

    vector<int> P;
    
    for (int i=2; i<=N; i++){
        bool c=true;
        for (auto u: P) {
            if (i%u == 0) {
                c=0;
                break;
            }
        }
        if (c) {
            P.push_back(i);
            steps++;
        }
    }

    // INSERT YOUR CODE HERE


    cout << steps << endl;

    return 0;
}
