// sort a LL of 0's,1's,2's 

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

Node* sortList(Node* head){
  if(!head || !head->next) return head;

  Node* zeroHead = new Node(-1);
  Node* oneHead = new Node(-1);
  Node* twoHead = new Node(-1);

  Node* zero = zeroHead;
  Node* one = oneHead;
  Node* two = twoHead;
  Node* temp = head;

  while(temp){
    if(temp->data == 0){
      zero->next = temp;
      zero = zero->next;
    }
    else if(temp->data == 1){
      one->next = temp;
      one = one->next;
    }
    else{
      two->next = temp;
      two = two->next;
    }
    temp = temp->next;
  }

  zero->next = (oneHead->next)? (oneHead->next): (twoHead->next);
  one->next = twoHead->next;
  two->next = NULL;

  Node* newhead = zeroHead->next;

  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return newhead;
}