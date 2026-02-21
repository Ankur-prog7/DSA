//find the first intersection point Y LL

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

Node* findIntersection(Node* firstHead,Node* secondHead){
  if(firstHead==NULL|| secondHead==NULL) return NULL;
  Node* t1 = firstHead;
  Node* t2 = secondHead;
  while(t1!=t2){
    t1=t1->next;
    t2=t2->next;
    if(t1==t2) return t1;
    if(t1==NULL) t1 = secondHead;
    if(t2==NULL) t2 = firstHead;
  }
  return t1;
}