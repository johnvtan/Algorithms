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
	
private:
	vector<int> sequence;           // the stored code value
	int length;
	int range; 
	
// private code operations:	
	void randomCode();
	void getGuessCode();
};
