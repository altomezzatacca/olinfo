// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;

    string L;
    cin >> L;

    string R;
    cin >> R;

    int ans = 0;


    // INSERT YOUR CODE HERE

	for (int i=0; i<N; i++){
		if (R[i] == 'R' && L[i] == 'R') break;
		ans++;
	}

    cout << ans << endl;

    return 0;
}
