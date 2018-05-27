#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Board board;
	cin >> board;
	string filename = board.draw(600);
    cout << "The Board is: \n\n"<<board<<endl<<endl;
	cout << "The file name created: "<< filename << endl << endl;
}
