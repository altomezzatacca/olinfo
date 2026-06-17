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

    int L = 0;
    
    int x=0;

    for (int i=1; true; i++) {
        x+=i*i;
        if(x<=N) L++; else break;
    }

    cout << L << endl;

    return 0;
}
