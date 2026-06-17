
// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

// input data
int N;
string S;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    cin.ignore();

	int r=0;
	
    for (int i=0; i<N; i++) {
        getline(cin, S);
		
		map<char, int> m;
		bool b=1;
		for(int i=0; i<S.size() && b==1; i++){
			char l=S[i];
			if (l>=97 && l<=122) l-=32;
			if (l>=65 && l<=90) m[l]++;
			if (m[l]>2) b=0;
		}
		if (b==1) r++;
    }

    cout << r << "\n"; // print the result
    return 0;
}
