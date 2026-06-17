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

    int N, M;
    cin >> N >> M;

    vector<string> level(N);

    if (N>M){
        cout <<-1;
        return 0;
    }

    for (int i=0; i<N; i++) {
        for(int j=i; j>0; j--) {
            level[i].push_back('#');
        }
        for(int j=i; j<M; j++) {
            level[i].push_back('.');
        }
    }

    for (int i = 0; i < N; ++i)
        cout << level[i] << endl;

    return 0;
}
