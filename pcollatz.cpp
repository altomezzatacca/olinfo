#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	int A, B, ris=0;
	in>>A>>B;
	
	for (int i=A; i<=B; i++){
		
		int x=i;
		int cont=0;
		
		while(x!=1){
			if(x%2==0) x/=2; else x=x*3+1;
			cont++;
		}
		x=i;
		
		for(int j=0; j<cont; j++){
			if (x==1) {
				ris++;
				break;
			}
			if(x%2==0) x/=2; else x=x*5+1;
		}
		
	}
	
	out<<ris;
	return 0;
}