// Implement Stack using Arrays
#include<bits/stdc++.h>
using namespace std;
class stackImplimentationUsingArray{
	int top =-1;
	int st [10];
	int length = sizeof(st)/sizeof(st[0]);

	void push(int x){
		if(top >= length-1){ //******************* imp case 
			cout << "stack is full";
			return;
		}
		top++;
		st[top] = x;
	}

	int peek(){
		if(top == -1) {
			cout<< "Empty";
			return -1;
		}
		return st[top];
	}

	int pop(){
		if(top==-1){
			cout << "Stack Underflow";
			return -1;
		}
		int popped = st[top];
		top--;
		return popped;
	}

	int size(){
		return top+1;
	}
};
