#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node(){
    data=0;
    next = NULL;
  }
  Node(int data1){
    data = data1;
    next = NULL;
  }
  Node(int data1,Node* next1){
    data = data1;
    next = next1;
  }
};

Node* flattenLinkedList(Node* head) {
  // If head is null or there is no next node
  if(head == NULL || head->next == NULL){
    return head; // Return head
  }

  Node* mergedHead = flattenLinkedList(head->next);
  
  head = merge2lists(head, mergedHead);
  return head;
}

Node* merge2lists(Node* list1,Node* list2){
  Node* dNode = new Node(-1);
  Node* res =dNode;
  while(list1!=NULL && list2!=NULL){
    if(list1->data < list2->data){
      res->next = list1;
      res = list1;
      list1 = list1->next;
    }
    else{
      res->next = list2;
      res = list2;
      list2 = list2->next;
    }
    res->next = NULL;
  }
  if(list1  != NULL) res->next = list1;
  else res->next = list2;

  return dNode->next;
}
