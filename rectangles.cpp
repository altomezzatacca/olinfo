#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int A;
    cin >> A;

    int B;
    cin >> B;

    int C;
    cin >> C;

    int K = 0;

	set<int> S;
	S.insert(A); S.insert(B); S.insert(C);
    switch((int)S.size()){
    	case 1:
    		K = 1;
    		break;
    	case 2:
    		K = 3;
    		break;
    	case 3:
    		K = 6;
    		break;
	}


    cout << K << endl;

    return 0;
}
