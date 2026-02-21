#include<bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node* random;
    
    Node(int _val) {
        data = _val;
        next = NULL;
        random = NULL;
    }
};

void insertCopyInBetween(Node* head){
  Node* temp = head;
  while(temp != NULL){
    Node* nextElem = temp->next;
    Node* copy = new Node(temp->data);

    copy->next = nextElem;
    temp->next = copy;

    temp = nextElem;
  }
}

void connectRandomPointers(Node* head){
  Node* temp = head;
  while(temp){
    Node* copyNode = temp->next;
    if(temp->random){
      copyNode->random = temp->random->next;
    }
    else{
      copyNode->random = nullptr;
    }
    temp=temp->next->next;
  }
}

Node* getDeepCopy(Node* head){
  Node* temp = head;
  Node* dNode = new Node(-1);
  Node* res = dNode;

  while (temp)
  {
    // creating neew list
    res->next = temp->next;
    res = res->next;

    // disconnecting and going back to initial state of LL
    temp->next = temp->next->next;
    temp = temp->next;
  }
  return  dNode->next;
 
}

Node* cloneLL(Node* head){
  insertCopyInBetween(head);
  connectRandomPointers(head);
  return getDeepCopy(head);
}