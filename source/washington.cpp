#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;

    vector<string> S(3), D(3);
    for (int i = 0; i < T; ++i) {
        cin >> S[0] >> S[1] >> S[2];
        cin >> D[0] >> D[1] >> D[2];

        int L = 0;

		int xs, ys=0, xd, yd=0;
		if(S[0][0]=='N'){
			ys=stoi(S[2]); //String TO Int
		}else {
			ys=stoi(S[2])%26;
			if (ys>0) ys-=26;
		}
		if(D[0][0]=='N'){
			yd=stoi(D[2]);
		} else {
			yd=stoi(D[2])%26;
			if (yd>0) yd-=26;
		}
		if(S[0][1]=='E'){
			xs=S[1][0] - 65;
		} else {
			xs=-(S[1][0] - 65);
		}
		if(D[0][1]=='E'){
			xd=D[1][0] - 65;
		} else {
			xd=-(D[1][0] - 65);
		}
		
		L = abs(xs-xd) + abs(ys-yd);
		
        cout << L << endl;
    }

    return 0;
}
