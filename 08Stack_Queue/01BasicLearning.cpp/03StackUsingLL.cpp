#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  
  Node(int x){
    data = x;
    next = nullptr;
  }
};

class StackUsingLL{
  Node* top;
  int size;

public:
  StackUsingLL(){
    top = nullptr;
    size =0;
  }

  void push(int x){
    Node* temp = new Node(x);
    temp->next = top;
    top = temp;
    size++;
  }


};

int main(){
  StackUsingLL st;
  st.push(10);
  st.push(20);
  return 0;
}