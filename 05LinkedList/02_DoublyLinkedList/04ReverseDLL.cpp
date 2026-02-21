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

Node* reverseDLL(Node* head){
  if(head==NULL || head->next == NULL){
    return head;
  }
  Node* prev = NULL;
  Node* current = head;
  // swapping of link
  while(current){
    prev = current -> prev;//last = current->back
    current-> prev = current->next;
    current->next = prev;

    current = current->prev;
  }
  return prev->prev;
}

