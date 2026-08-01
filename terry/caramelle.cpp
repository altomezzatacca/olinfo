// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> V(N);
        for (int i = 0; i < N; ++i)
            cin >> V[i];

        int c = 0, temp; //c = mcm

        // INSERISCI IL TUO CODICE QUI

		c=V[0];

		for(int i=0; i<N; i++){
			while(c%V[i]!=0){
				c+=V[0];
				i=0;
			}
		}

        cout << "Case #" << test << ": ";
        cout << c << endl;
    }

    return 0;
}