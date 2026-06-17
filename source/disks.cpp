// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
	ifstream cin("input.txt");
	ofstream cout("output.txt");

    long long A, B, T;
    cin >> A >> B >> T;
    
    long long tot=0, r=0, r1=T;
	int daily=B-A;
	
	for(int i=0; i<24; i++){
		tot+=24-i;
		if (i<B){
			if(i<A) r+=daily;
			else r+=B-i;
		}
		long long j=(T-tot)/24;
		tot+=24*j;
		r+=daily*j;
		tot+=A;
		while(tot<T){
			tot++;
			r++;
		}
		r1=min(r, r1);
		r=0;
		tot=0;
	}
	
    cout << r1 << endl; // print the result

    return 0;
}
