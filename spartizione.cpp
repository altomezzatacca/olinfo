#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	long long G, P, x=0, ris=0;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>G>>P;
	
	for (int i=1; x<G; i++){
		if(x+i>G){
			ris+=G-x;
			x+=i;
		} else {
			ris+=i;
			x+=i;
		}
		x+=P-1;
	}
	
	out<<ris;
	
	return 0;
}