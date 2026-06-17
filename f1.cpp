// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> H, V;

int main() {
    //  uncomment the following lines if you want to read/write from files
    //  ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
	int _min = 1e9, h = 0, v = 0;
	bool __min = 0;
    for (int i = 0; i < N; i++){
        cin >> H[i];
		_min = min(_min, H[i]);
		h += H[i];
	}
    V.resize(N);
    for (int i = 0; i < N; i++){
        cin >> V[i];
		if(V[i] < _min){
			_min = V[i];
			__min = 1;
		}
		v += V[i];
	}

	cout << (h < v ? "Hamilton" : "Verstappen") << "\n";
    cout << (__min ? "Verstappen" : "Hamilton") << endl;
    return 0;
}