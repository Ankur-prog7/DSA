#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next,*prev;
  Node(){
    this->data=0;
    next = NULL;
    prev = NULL;
  }
  Node(int data1){
    this->data = data1;
    this->next = NULL;
    this->prev = NULL;
  }
  Node(int data1,Node* next1,Node* prev1){
    this->data = data1;
    this->next = next1;
    this->prev = prev1;
  }
};

Node* addTwoNo(Node* num1,Node* num2){
  Node* dummyHead = new Node(-1);
  Node* curr = dummyHead;
  Node* temp1 = num1;
  Node* temp2 = num2;
  int carry = 0;
  while(temp1!= NULL || temp2!= NULL){
    int sum = carry;
    if(temp1) sum += temp1->data;
    if(temp2) sum += temp2->data;
    Node* newNode = new Node(sum % 10);
    carry = sum/10;
    
    curr->next = newNode;
    curr = curr->next;

    if(temp1) temp1 = temp1->next;
    if(temp2) temp2 = temp2->next;
  }
  if(carry){
    Node* newNode = new Node(carry);
    curr->next = newNode;
  }
  return dummyHead->next;
}