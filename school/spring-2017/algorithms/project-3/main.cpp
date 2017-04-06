// Mary Forde
// John Tan
// Project 3
// This file runs the global search function 

#include"global.h"

using namespace std;

int main() 
{
	
	int sel;

	while (true) 
	{
		cout << "Please enter the sorting algorithm you wish to use. Your options are as follows:\n"
			 <<	"0 - selection sort\n1 - quick sort\n2 - heap sort" << endl;
		cin >> sel;
		
		
		if (cin.fail() || sel < 0 || sel > 2) 
		{
			cout << "Invalid value entered. Please try again." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else 
		{
			break;
		}
	}
	cin.clear();
	cin.ignore(256, '\n');
					
	search(sel);	
	
	return 0;
}
