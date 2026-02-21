// find length of loop in LL
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node(){
    this->data=0;
    next = NULL;
  }
  Node(int data1){
    this->data = data1;
    this->next = NULL;
  }
  Node(int data1,Node* next1){
    this->data = data1;
    this->next = next1;
  }

};

int length(Node* slow,Node* fast){
  int cnt=1;
  fast=fast->next;
  while(slow!=fast){
    cnt++;
    fast=fast->next;
  }
  return cnt;
}
bool LengthOfLL(Node* head){
  Node* fast = head;
  Node* slow = head;
  while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow=fast) return length(slow,fast);
  }
  return false;
}