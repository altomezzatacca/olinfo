// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        long long N, x_n, best;
        cin >> N;
        
        int msb=0, k=N;
	    while (k>0) {
	        k>>=1;
	        msb++;
	    }

		switch (N%4){
	    	case 0:
	    		x_n=N;
                best=(1<<msb)-1;
	    		break;
	    	case 1:  //ok
	    		x_n=1;
                best=N;
	    		break;
	    	case 2:  //ok
	    		x_n=N+1;
                best=(1<<msb)-1;
	    		break;
	    	case 3:  //ok
	    		x_n=0;
                best=N;
	    		break;
		}
		
        // print the result
        cout << x_n << " " << best << "\n";
    }


    return 0;
}
