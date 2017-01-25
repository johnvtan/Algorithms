#include"code.h"
#include<iostream>
#include<vector>
#include"time.h"
#include"stdlib.h"

using namespace std;

int main() {
	//initialize the seed for the random number generator
	srand(time(NULL));
	
	code secretCode(5, 9);
	secretCode.printCode();
	code guessCode(5);
	guessCode.printCode();
	
	cout << "NumCorrect: " << secretCode.checkCorrect(guessCode) << endl;
	
	return 0;
}
