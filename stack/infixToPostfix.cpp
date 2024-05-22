#include<iostream>
#include<string>
#include<stack>
using namespace std;
int prec(char ch){
	if(ch == '*' || ch == '/')
		return 2;
	if(ch == '+' || ch == '-')
		return 1;
	return 0;
}
bool isOperator(char ch){
	if(ch == '*' || ch == '/' || ch == '-' || ch == '+' )
		return true;
	return false;
}


string infixToPostfix(string exp){
        stack<char> st;
	
	string postfix = "";
	for(int i=0; exp[i] != '\0' ; i++){
		char ch = exp[i];
		if(isOperator(ch)){
			while(!st.empty() && (prec(ch) <= prec(st.top()))){
				postfix.push_back(st.top());
				st.pop();
			}
			st.push(ch);
		}
		else if(ch == '(')
			st.push(ch);
		else if(ch == ')'){
			while(st.top() != '('){
				postfix.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else{
			postfix.push_back(ch);
		}}
	while(!st.empty()){
		postfix.push_back(st.top());
		st.pop();
	}
	return postfix;
}
				

       



int main(){

        string exp = "8+3*(9-6)/2+6/2";
        string postfix = infixToPostfix(exp);
        for(int i=0; postfix[i] != '\0'; i++){
                cout<<postfix[i];
        }
	cout << endl;
}
