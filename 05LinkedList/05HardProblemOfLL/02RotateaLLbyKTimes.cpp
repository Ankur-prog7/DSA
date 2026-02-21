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

Node* findNthNode(Node* temp,int k){
  int cnt =1;
  while (temp!=NULL)
  {
    if(cnt==k) return temp;
    cnt++;
    temp = temp->next;
  }
  return temp;
  
}

Node* rotate(Node* head,int k){
  if(head == NULL || k==0) return head;
  Node* tail =head;
  int len =1;
  while (tail->next != NULL)
  {
    tail = tail->next;
    len += 1;
  }
  if(k%len == 0) return head;
  k =k%len;

  tail->next = head;
  Node* newLastNode = findNthNode(head,len-k);

  head =newLastNode->next;
  newLastNode->next =NULL;

  return head;
}