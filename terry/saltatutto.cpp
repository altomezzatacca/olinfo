// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
	ifstream cin("saltatutto_input_1.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> R(N);
        for (int i = 0; i < N; ++i)
            cin >> R[i];

        string ris = "";


        for(int i=0; i<N-1;){
        	if(R[i+1]==0){
        		i++;
        		ris.push_back('A');
			} else{
				i+=2;
				ris.push_back('S');
			}
		}
		if(!R[N-1]) ris.push_back('A');


        cout << "Case #" << test << ": ";
        cout << ris << endl;
    }

    return 0;
}