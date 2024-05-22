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
			if(postfix.back() != ' ')
			postfix.push_back(' ');
			while(!st.empty() && (prec(ch) <= prec(st.top()))){
				postfix.push_back(st.top());
				postfix.push_back(' ');
				st.pop();
			}
			st.push(ch);
		}
		else if(ch == '(')
			st.push(ch);
		else if(ch == ')'){
			postfix.push_back(' ');
			while(st.top() != '('){
				postfix.push_back(st.top());
				postfix.push_back(' ');
				st.pop();
			}
			st.pop();
		}
		else{
			postfix.push_back(ch);
		}}
	postfix.pop_back();
	while(!st.empty()){
		if(postfix.back() != ' ')
		postfix.push_back(' ');
		postfix.push_back(st.top());
		//postfix.push_back(' ');
		st.pop();
	}
	//postfix.pop_back();
	return postfix;
}
