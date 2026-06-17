#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    string A;
    cin >> A;

    string B;
    cin >> B;

    string C = "";
    
    bool x=0;
    
    for(int i=0; i<A.size(); i++){
    	if(i<B.size() && B[i]>A[i]+1 && A[i]!='z'){
    		C.push_back(A[i]+1);
    		cout <<C; 
    		return 0;
		}
		if(B[i]>A[i]){
			x=1;
		}
		C.push_back(A[i]);
		if (x && A[i]!='z' && i!= B.size()-1){ 
			C.pop_back();
			C.push_back(A[i]+1);
		}
		if (x && B[i]!='a' && C[i]>A[i]){
			cout <<C;
			return 0;
		}
	}
	for (int i=A.size(); i<B.size(); i++){
		C.push_back('a');
		if (B[i]>'a' || i+1<B.size()){
			cout << C;
			return 0;
		}
	}

	cout <<-1;

    return 0;
}