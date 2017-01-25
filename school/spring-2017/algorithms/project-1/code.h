#include <vector>

using namespace std;

class code {
public:
	code(int n, int m);
	code(int n);
	int checkCorrect(const code &c);
	int checkIncorrect(const code &c);
	void printCode();
	int getIndex(int i) const;
	
private:
	vector<int> sequence;
	void randomCode(int n, int m);
	void getGuessCode(int m);
};
