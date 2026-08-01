#include <bits/stdc++.h>
using namespace std;

// input data
int N;
vector<int> D;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    D.resize(N);
    for (int i=0; i<N; i++)
        cin >> D[i];

    sort(begin(D), end(D));
    bool b = 1;
    for(int i = 0; i < N - 1; i++){
      if(D[i] >= D[i + 1]) b = 0;
    }

    cout << (b ? "Ok" : "Impossible"); // print the result
    return 0;
}
