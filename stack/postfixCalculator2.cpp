#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class stack{
  private:
    int* arr;
    int last;
    int size;
  public:
    stack(int size){
      arr = new int[size];
      last = -1;
      this->size = size;
    }
    bool isEmpty(){
      if(last == -1)return true;
      return false;
    }
    bool isFull(){
       if((last + 1) == size) return true;
       return false;
    }
    void push_back(int data){
      if(isFull()){
        cout << "Stack Overflow" <<endl;
        return;
      }
      arr[++last] = data;
    }
    void pop_back(){
      if(isEmpty()){
        cout<< "Stack is Empty" << endl;
        return;
      }
        last--;
    }
    int top(){
	    if(isEmpty()){
		    cout<< "Stack is Empty" << endl;
		    return -1;
	    }
	    return arr[last];
}
};
int postfixCalculate(string exp, stack &st){
    string str;
	
	char ch;
	for(int i=0; exp[i] != '\0'; i++){
		ch = exp[i];
        if(ch == ' '){
			int l = stoi(str);
			st.push_back(l);
			str.clear();
		}

		else if(ch >= '0' && ch <= '9'){
			str.push_back(ch);
			
		}
		
		else if( ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			int a = st.top();
			st.pop_back();
			int b = st.top();
			st.pop_back();
			switch(ch){
				case '+': 
					  st.push_back(a+b);
					  break;
			        case '-':
			                  st.push_back(b-a);
					  break;
				case '*':
					  st.push_back(a*b);
					  break;
				case '/': 
					  st.push_back(b/a);
					  break;
			}
			
			if(exp[i+1] != '\0')
			    i++;

		}
	}
	return st.top();
}

int main(int argc, char* argv[]){
        fstream myfile(argv[1]);
	stack st(100);
	string exp;
	char ch;
	myfile >> noskipws;
	while(myfile >> ch)
		exp.push_back(ch);
	int result = postfixCalculate(exp, st);
		
	
	cout << result << endl;
	myfile.close();
	return 0;
}

