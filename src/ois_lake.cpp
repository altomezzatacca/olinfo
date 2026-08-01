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

    vector<string> city(N);
    for (int i = 0; i < N; ++i)
        cin >> city[i];

    int P = 0;
	
	for (int i=1; i<N-1; i++){
		for (int j=1; j<M-1; j++){
			if (city[i][j] == '#') {
				if (city[i+1][j] == '.') P++;
				if (city[i-1][j] == '.') P++;
				if (city[i][j+1] == '.') P++;
				if (city[i][j-1] == '.') P++;
			}
		}
	}


    cout << P << endl;

    return 0;
}
