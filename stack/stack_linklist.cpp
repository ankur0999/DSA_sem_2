#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node* next;
	public:
	node(int data){
		this->data = data;
		next = NULL;
	}
};

class stack{
    node* top;
    node* head;
	public:
    stack(){
	    top = NULL;
	    head = NULL;
    }
    bool isEmpty(){
	    if(top == NULL) return true;
	    return false;
    }
    void push_back(int d){
	    if(isEmpty()){
		    head = new node(d);
		    top = head;
		    return;
	    }
	    node* tmp = new node(d);
	    top->next = tmp;
	    top = tmp;
    }
    void pop_back(){
	    if(isEmpty()){
		    cout << " Stack is Empty " << endl;
		    return;
	    }
	    node* curr = head;
	    node* prev = NULL;
	    while(curr->next){
		    prev = curr;
		    curr = curr->next;
	    }
	    delete[] curr;
		top = prev;
		if(prev)
	    prev->next = NULL;
	    
    }
    int peek(){
	    if(isEmpty()){
		    cout<< " Stack is Empty " << endl;
		    return -1;
	    }
	    return top->data;
    }
};

int main(){
        stack st;
        st.push_back(12);
		cout<< st.peek() << endl;
		st.push_back(144);
		st.push_back(13);
		st.push_back(169);
		cout<< st.peek() << endl;
		st.pop_back();
		cout<< st.peek() << endl;
		st.pop_back();
		st.pop_back();
		st.pop_back();
		//st.pop_back();
        st.push_back(14);
		st.push_back(196);
		cout<< st.peek() << endl;
}



