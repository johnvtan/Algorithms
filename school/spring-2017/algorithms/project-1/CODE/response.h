// Mary Forde, John Tan
// Project 1

#include<iostream>
#include<stdlib.h>

// This file declares the "response" class

using namespace std;

class response {
	public:

        // Constructors 
		response(int c, int i);	        
		response() { };                 // empty constructor
            
                // Public setter & getter functions
		void setCorrect(int x);
		void setIncorrect(int x);
		int getCorrect() const;
		int getIncorrect() const;

                // Operator Overloading functions
		friend ostream& operator<< (ostream& ostr, const response& r);
		friend bool operator== (const response& r1, const response& r2);
	private:
		int numCorrect;
		int numIncorrect;
};

