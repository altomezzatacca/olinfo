#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long N;
	pair<int, int> P;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>N;
	long long x=N;
	
	for (int i=2; i<=x; i++){
		if (x%i==0) {
			x/=i;
			P.first=i;
			break;
		}
	}
	for (int i=2; i<=x; i++){
		if (x%i==0) {
			x/=i;
			P.second=i;
			break;
		}
	}
	for (int i=2; i<=x; i++){
		if (x%i==0) {
			out<<-1;
			return 0;
		}
	}
	
	out<<P.first<<" "<<P.second;
	
	return 0;
}