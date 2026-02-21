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

Node* startingPoint(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow==fast){
      slow = head;
      while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
      }
      return slow;
    }
  }
  return NULL;
}