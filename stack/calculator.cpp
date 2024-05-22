#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<fstream>
#include "infixToPostfix.h"
#include "postfixCalculate.h"


				

       



int main(int argc, char* argv[]){
        fstream infix(argv[1]); 
        
	infix >> noskipws;
	char ch;
	string exp;

	while(infix >> ch)
        exp.push_back(ch);
        
    string postfix = infixToPostfix(exp);
    int result = postfixCalculate(postfix);
    cout << result;
    
	cout << endl;
}
