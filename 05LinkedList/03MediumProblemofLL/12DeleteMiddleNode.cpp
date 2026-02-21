// delete middle node in LL

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

// we have to find 1st middle ,reach the node before the middle node
Node* deleteMiddleNode(Node* head){
  if(head==NULL||head->next==NULL) return NULL;
  Node* slow = head;
  Node* fast = head;
  fast=fast->next->next;
  while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  Node* middle=slow->next;
  slow->next = slow->next->next;
  free(middle);
  return head;
}