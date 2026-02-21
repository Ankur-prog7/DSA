// Infix to Postfic Conversion using Stack
#include<bits/stdc++.h>
using namespace std;

int prec(char c){
  if(c=='^') return 3;
  else if(c=='/' || c=='*') return 2;
  else if(c=='+'|| c=='-') return 1;
  else return -1;
}

void infixToPostfix(string s){
  stack<char>st;
  string result;

  for(char c:s){
    if((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z') || (c>='0' && c<= '9'))
    result += c;
    else if( c == '(') {
      st.push('(');
    }
    else if(c==')'){
      while(st.top() != '('){
      result += st.top();
      st.pop();
      }
      st.pop();
    }
    // if an operator is scanned
    else {
      while(!st.empty() && prec(s[c]) <= prec(st.top())){
        result += st.top();
        st.pop();
      }
      st.push(c);//push your curr operator in stack
    }
  }
  while (!st.empty()){
    result += st.top();
    st.pop();
  }
  cout << "Postfix expression" << result <<endl;//output the result;
}