// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Angolo(int h, int b, int a, int &acuti, int &ottusi, int &retti){
	if(a*b<h*h) ottusi++;
	if(a*b==h*h) retti++;
	if(a*b>h*h) acuti++;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int topLeftX, topLeftY;
    cin >> topLeftX >> topLeftY;

    int topRightX, topRightY;
    cin >> topRightX >> topRightY;

    int bottomRightX, bottomRightY;
    cin >> bottomRightX >> bottomRightY;

    int bottomLeftX, bottomLeftY;
    cin >> bottomLeftX >> bottomLeftY;

    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];

    int K = 0;

	for (int i=0; i<N; i++){
		int acuti=0, ottusi=0, retti=0;
        int b=min(X[i]-bottomLeftX, bottomRightX-X[i]);
		Angolo(Y[i]-bottomLeftY, b, bottomRightX-bottomLeftX-b, acuti, ottusi, retti);
        b=min(Y[i]-bottomLeftY, topLeftY-Y[i]);
		Angolo(X[i]-bottomLeftX, b, topLeftY-bottomLeftY-b, acuti, ottusi, retti);
        b=min(Y[i]-bottomRightY, topRightY-Y[i]);
		Angolo(topRightX-X[i], b, topRightY-bottomRightY-b, acuti, ottusi, retti);
        b=min(topRightX-X[i], X[i]-topLeftX);
		Angolo(topRightY-Y[i], b, topRightX-topLeftX-b, acuti, ottusi, retti);
		if (acuti==2 && ottusi==2) K++;
	}

    cout << K << endl;

    return 0;
}
