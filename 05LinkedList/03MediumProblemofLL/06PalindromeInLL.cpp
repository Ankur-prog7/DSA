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
  if(head == NULL || head->next == NULL){
    return head;
  }
  Node* newHead = reverseLL(head->next);
  Node* front = head->next;
  front->next = head;
  head->next = NULL;

  return newHead;
}

bool isPalindrome(Node* head){
  if(head == NULL || head->next == NULL) return true;
  Node* slow = head;
  Node* fast = head;
  while (fast->next != NULL && fast->next->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node* newHead = reverseLL(slow->next);
  Node* first = head;
  Node* second = newHead;
  while (second)
  {
    if(first->data != second->data) {
      reverseLL(newHead);
      return false;
    }
    first = first->next;
    second = second->next;
  }
      reverseLL(newHead);
  return true;
  
}