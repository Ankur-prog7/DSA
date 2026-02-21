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

Node* OddEven(Node* head){
  Node* odd = head;
  Node* even = head->next;
  Node* evenHead = head->next;

  while(even!=NULL && even->next != NULL){
    odd->next = odd->next->next;/// linking odd to next odd
    even->next = even->next->next;


    odd = odd->next; // move odd forward
    even = even->next;
  }
  odd->next = evenHead;//attach even list after odd list
    return head;

  return head;
}