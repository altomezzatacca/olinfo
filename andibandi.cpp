// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int Sa, Ta, Ua;
    cin >> Sa >> Ta >> Ua;

    int Sb, Tb, Ub;
    cin >> Sb >> Tb >> Ub;

    int D = abs(Sa-Sb)+abs(Ta-Tb)+abs(Ua-Ub);


    cout << D << endl;

    return 0;
}
