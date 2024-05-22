#include<iostream>
#include<string>
#include<stack>
using namespace std;

string infixToPostfix(string exp, stack<char> st){
        string postfix = "";
        for(int i=0; exp[i] != '\0'; i++){
                if(exp[i] >= '0' && exp[i] <= '9')
                    postfix.push_back(exp[i]);
                if(exp[i] == '*')
                        st.push(exp[i]);
                if(exp[i] == '+'){
                        if(st.empty())
                                st.push(exp[i]);
                        else{
                                while(!st.empty()){
                                postfix.push_back(st.top());
                                st.pop();
                                }
                                st.push(exp[i]);
                        }
                }
        }
        while(!st.empty()){
                postfix.push_back(st.top());
                st.pop();
        }
        postfix.push_back('\0');
        return postfix;
}


int main(){
stack<char> st;
        string exp = "9+4*5+6";
        string postfix = infixToPostfix(exp, st);
        for(int i=0; postfix[i] != '\0'; i++){
                cout<<postfix[i];
        }
}
