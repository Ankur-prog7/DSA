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


Node* middle(Node* head){
  Node* fast = head;
  Node* slow = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast=fast->next->next;
  }
  return slow;
}