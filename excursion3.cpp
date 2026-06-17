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

    int A;
    cin >> A;

    int F;
    cin >> F;

    int M;
    cin >> M;

    int S = 0;
    int W = 0;
    
    S += A + 2*M + 3*F;
    W += A + M + F;

    cout << S << endl;
    cout << W << endl;

    return 0;
}
