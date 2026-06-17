#include <bits/stdc++.h>
using namespace std;

void game(int &X, int &Y, int sit){
	switch(sit){
		case 0:
			break;
		case 1:
			break;
		case 2:
			X=Y+1;
			break;
		case 3:
			Y=X+1;
			break;
		case 4:
			X=Y-1;
			break;
		case 5:
			Y=X-1;
			break;
		case 6:
			X=Y-1;
			break;
		case 7:
			Y=X+1;
			break;
		case 8:
			X=Y+1;
			break;
		case 9:
			Y=X-1;
			break;
		case 20:
			cout <<"hell nah";
			break;
	}
	return;
}

int check(int &X, int &Y, int par_X, int par_Y){
	if(X==0 && Y==1) return 15;
	if(X==1 && Y==0) return 15;
	if(par_X == 1 && par_Y == 0 && X==Y+1) return 0;
	if(par_X == 0 && par_Y == 1 && Y==X+1) return 1;
	if(par_X == 0 && par_Y == 0 && X>Y) return 2;
	if(par_X == 0 && par_Y == 0 && X<Y) return 3;
	if(par_X == 1 && par_Y == 1 && X>Y) return 4;
	if(par_X == 1 && par_Y == 1 && X<Y) return 5;
	if(par_X == 0 && par_Y == 1 && X>Y) return 6;
	if(par_X == 0 && par_Y == 1 && X<Y) return 7;
	if(par_X == 1 && par_Y == 0 && X>Y) return 8;
	if(par_X == 1 && par_Y == 0 && X<Y) return 9;
	return 20;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int X, Y;
    cin >> X >> Y;

    char winner = 'C';
    int new_X = X, new_Y = Y;
    int sit;

    int par_X=X%2, par_Y=Y%2;
	if (par_X==0 && par_Y==1 && Y==X+1){
		winner = 'N';
	} else if (par_X==1 && par_Y==0 && X==Y+1) winner = 'N';
	
	sit=check(new_X, new_Y, par_X, par_Y);
	game(new_X, new_Y, sit);
	
	// print the winner
	cout << winner << endl;
	cout.flush();
	
    // while there is no winner, print your move and read the opponent's move
    if (winner=='C'){
	    while (sit!=15){
			cout << new_X << " " << new_Y << "\n";
		    cout.flush();
		    sit=check(new_X, new_Y, new_X%2, new_Y%2);
		    if (sit!=15){
		    	cin >> new_X >> new_Y;
		    	sit=check(new_X, new_Y, new_X%2, new_Y%2);
				game(new_X, new_Y, sit);
			}
		}
	} else {
		while (sit!=15){
		   	cin >> new_X >> new_Y;
		   	sit=check(new_X, new_Y, new_X%2, new_Y%2);
			game(new_X, new_Y, sit);
			cout << new_X << " " << new_Y << "\n";
			cout.flush();
			sit=check(new_X, new_Y, new_X%2, new_Y%2);
		}
	}

    return 0;
}