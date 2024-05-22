int postfixCalculate(string exp){
    string str;
    stack<int> st;
	
	char ch;
	for(int i=0; exp[i] != '\0'; i++){
		ch = exp[i];
        if(ch == ' '){
			int l = stoi(str);
			st.push(l);
			str.clear();
		}

		else if(ch >= '0' && ch <= '9'){
			str.push_back(ch);
			
		}
		
		else if( ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			switch(ch){
				case '+': 
					  st.push(a+b);
					  break;
			        case '-':
			                  st.push(b-a);
					  break;
				case '*':
					  st.push(a*b);
					  break;
				case '/': 
					  st.push(b/a);
					  break;
			}
			
			if(exp[i+1] != '\0')
			    i++;

		}
	}
	return st.top();
}
