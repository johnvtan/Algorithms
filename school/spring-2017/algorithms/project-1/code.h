// Mary Forde, John Tan
// Project 1a

// This file declares the "code" class

#include <vector>
using namespace std;

class code 
{
public:
// constructors:	
	code(int n, int m);
	code(const code &secretCode);
	
// public code operations:	
	int checkCorrect(const code &c) const;
	int checkIncorrect(const code &c) const;
	void printCode() const;
	int getIndex(int i) const;
	int getLength() const;
	int getRange() const;
	vector<int> getSequence() const;
	
private:
	vector<int> sequence;           // the stored code value
	int length;                     // length of the code
	int range;                      // range is [0:range)
	
// private code operations:	
	void randomCode();              // generates random secret code
	void getGuessCode();            // lets user input the code
};
