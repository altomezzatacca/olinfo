#include<bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> R(N);
    for (int i = 0; i < N; ++i)
        cin >> R[i];

    vector<int> P(N); P[0] = 1;

    bool b = 0;

    for(int i = 1; i < N && !b; i++)
        if(R[i] > R[i - 1] + 1) b = 1;

    if(!b)
      for(int i = 1; i < N; i++)
        P[i] = (R[i] == R[i - 1] ? P[i - 1] : i + 1);
    else
      for(int i = 1; i < N; i++)
        P[i] = (R[i] == R[i - 1] ? P[i - 1] : P[i - 1] + 1);

    for (int i = 0; i < N; ++i)
        cout << P[i] << " ";
    cout << endl;

    return 0;
}
