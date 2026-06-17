// NOTE: it is recommended to use this even if you don't understand the following code.
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N, M;
        cin >> N >> M;
        string W;
		int tA, tB, tC;
		switch(N % 3){
			case 0:
				tA = N/3;
				tB = N/3;
				tC = N/3;
				break;
			case 1:
				tA = N/3 + 1;
				tB = N/3;
				tC = N/3;
				break;
			case 2:
				tA = N/3 + 1;
				tB = N/3 + 1;
				tC = N/3;
				break;
		}
		int B1, B2;
		switch(M % 2){
			case 0:
				B1 = M/2;
				B2 = M/2;
				break;
			case 1:
				B1 = M/2 + 1;
				B2 = M/2;
				break;
		}
		int tom = 0, fil = 0;
		tom++;
		if(B2 > tC){
			fil++;
		} else if(B2 < tC){
			tom++;
		}
		if(B1 > tB){
			fil++;
		} else if(B1 < tB){
			tom++;
		}
		if(tom >  fil) W = "tommaso";
		if(tom <  fil) W = "filippo";
		if(tom == fil) W = "draw";

        cout << W << endl;
    }

    return 0;
}
