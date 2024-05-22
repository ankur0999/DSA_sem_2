#include<iostream>
#include<string>
#include<stack>
using namespace std;
int prec(char ch){
	if(ch == '*' || ch == '/')
		return 2;
	else if(ch == '+' || ch == '-')
		return 1;
    else
	    return 0;
}
bool isOperand(char ch){
	if(ch == '*' || ch == '/' || ch == '-' || ch == '+' )
		return false;
	return true;
}


string infixToPostfix(string exp){
    stack<char> st;
    st.push('#');
	int i=0;
	string postfix;
	while(exp[i] != '\0'){
		
		char ch = exp[i];
		
		if(isOperand(ch)){
			postfix.push_back(ch);
		}
		
		else{
            if(prec(ch) > prec(st.top()))
			st.push(ch);
            else
                {
                    while(prec(ch) <= prec(st.top())){  
                             postfix.push_back(st.top());
                             st.pop();
                       }
					   st.push(ch);
                }
		}
        i++;
        }
	while(!st.empty()){
		postfix.push_back(st.top());
		st.pop();
	}
	
	
    
	return postfix;
}
				

       



int main(){

        string exp = "8+3*9-6/2+6/2";
        string postfix = infixToPostfix(exp);
        for(int i=0; postfix[i] != '\0'; i++){
                cout<<postfix[i];
        }
	cout << endl;
}
