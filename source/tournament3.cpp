// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    int winner = 0, runnerup = 0;

    int x=0, y=N/2;
    
    for (int i=0; i<N/2; i++) if (P[i]>P[x]) x=i;
    for (int i=N/2; i<N; i++) if (P[i]>P[y]) y=i;
    
    if (P[x]>P[y]) {
        winner=x;
        runnerup=y;
    } else {
        winner=y;
        runnerup=x;
    }

    cout << winner << " " << runnerup << endl;

    return 0;
}
