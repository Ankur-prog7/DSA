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
  Node(int data1,Node* next1,Node* prev1){
    this->data = data1;
    this->next = next1;
  }
};

Node* removeKthNode(Node* head,int k){
  Node* fast =head;
  Node* slow = head;
  for (int i = 0; i < k; i++)
  {
    fast = fast->next;
  }
  if(fast == NULL ) return head->next;
  while(fast->next!=NULL){
    fast= fast->next;
    slow = slow->next;
  }
  Node* delNode = slow->next;
  slow->next = slow->next->next;
  delete(delNode);

  return head;
  
}