// Mary Forde, John Tan
// Project 1a

// This file declares the "code" class

#include <vector>

using namespace std;

class code
{
public:
// constructors:	
	code(int n, int m);           // constructor for secretCode
	code(const code &secretCode); // constructor for guessCode
	
// public code operations:	
	int checkCorrect(const code &c) const;
	int checkIncorrect(const code &c) const;
	void printCode() const;
	int getIndex(int i) const;
	int getLength() const;
	int getRange() const;
	vector<int> getSequence() const;
	
private:
	vector<int> sequence; // the stored code value
	int length;           // the length of the sequence
	int range; 			  // the range of values in the sequence [0:range)
	
// private code operations:	
	void randomCode();
	void getGuessCode();
};
