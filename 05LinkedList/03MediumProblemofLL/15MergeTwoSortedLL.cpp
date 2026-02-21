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

Node* sortTwoList(Node*l1,Node*l2){
  Node*t1 =l1;
  Node*t2 = l2;
  Node* dNode = new Node(-1);
  Node* temp = dNode;
  while(t1!=NULL && t2!=NULL){
    if(t1->data < t2->data){
      temp->next = t1;
      temp = t1;
      t1 = t1->next;
    }
    else{
      temp->next =t2;
      temp =  t2;
      t2 = t2->next;
    }
  }
  if(t1) temp->next = t1;
  else temp->next = t2;
  return dNode->next;
}