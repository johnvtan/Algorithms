#include"code.h"
#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main() {
        int numCorrect;    
        // initializing random seed number
        srand(time(NULL));

	code secretCode(5,9);
        secretCode.printCode();
        code guessCode(5);
       
       // secretCode.printCode();
       // guessCode.printCode();
    
        numCorrect = secretCode.checkCorrect(guessCode);
        cout << "# Correct is: " << numCorrect << endl;
	return 0;
}
