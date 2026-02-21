// reverse Nodes in K group of LL

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

Node* reverseLL(Node* head){
  Node* temp =head;
  Node* prev = NULL;
  while(temp){
    Node* front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;

  }
  return prev;
}

Node* getKthNode(Node* temp ,int k){
   k -= 1;
   while(temp && k>0){
    k--;
    temp = temp->next;
   }
   return temp;
}

Node* kReverse(Node* head,int k){
  Node* temp = head;
  Node* prevLast = NULL;
  while (temp)
  {
    Node* kThNode = getKthNode(temp,k);
    if(kThNode == NULL){
      if(prevLast == NULL){
        prevLast->next = temp ;
        break;

      }
    }
    Node* nextNode = kThNode->next;
    kThNode->next=NULL;
    reverseLL(temp);
    if(temp == head){
      head= kThNode;
    }
    else{
      prevLast->next = kThNode;
    }
    prevLast = temp;
    temp = nextNode;
  }
  return head;
}