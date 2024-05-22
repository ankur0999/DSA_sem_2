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
int main(int argc, char* argv[]){
	fstream myfile(argv[1]);
	stack st(100);
	char ch;
	while(myfile >> ch){
		if(ch >=48 && ch <=57){
			st.push_back(int(ch-48));
		}
		
		if( ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			int a = st.top();
			st.pop_back();
			int b = st.top();
			st.pop_back();
			switch(ch){
				case '+': 
					  st.push_back(b+a);
					  break;
			        case '-':
			                  st.push_back(b-a);
					  break;
				case '*':
					  st.push_back(b*a);
					  break;
				case '/': 
					  st.push_back(b/a);
					  break;
			}
		}
	}
	cout << st.top() << endl;
	myfile.close();
	return 0;
}

