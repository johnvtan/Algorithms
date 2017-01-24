#include <vector>

class code {
public:
	code(int n, int m);
	int checkCorrect(code c);
	int checkIncorrect(code c);
	void printCode();
	
private:
	vector<int> sequence;
	void randomCode(int n, int m);
};
