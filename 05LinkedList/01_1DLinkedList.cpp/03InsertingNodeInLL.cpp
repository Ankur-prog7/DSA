#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
public:
  Node(int data1,Node* next1){
    data=data1;
    next = next1;
  }
public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }  
};

Node* createNode(vector<int>&a){
  Node* head = new Node(a[0]);
  Node* mover = head;
  for (int i = 1; i < a.size(); i++)
  {
    Node* temp = new Node(a[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

// insert node at beigning or insert head
Node* insertHead(Node* head,int val){
  Node* temp = new Node(val,head);
  return temp;
}

// insert node at last 
Node* insertTail(Node* head,int val){
  if(head == NULL){
    return new Node(val);
  }
  Node* temp = head;
  while(temp->next){
    temp=temp->next;
  }
  Node* newNode = new Node(val);
  temp->next = newNode;  
  return head;
}

// insert at K
Node* insertAtk(Node* head,int el,int k){
  //checking
  if(head == NULL){
    if(k==1){
      return new Node(el);
    }else{
      return head;
    }
  }//inserting 
  if(k==1){
    return new Node(el,head);
  }
  int cnt =0;
  Node* temp = head;
  while (temp)
  {
    cnt++;
    if(cnt == (k-1)){
      Node* x = new Node(el,temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}

// insert elem before value x
Node* insertBeforeValue(Node* head,int el,int val){
  //checking
  if(head == NULL){
    return NULL;
  }//inserting 
  if(head->data == val){
    return new Node(el,head);
  }
  Node* temp = head;
  while (temp->next)
  {
    if(temp->next->data == val){
      Node* x = new Node(el,temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}




int main(){
  vector<int>a={2,4,3,7};
  Node* head = createNode(a);
  // head = insertHead(head,12);
  // head = insertTail(head,12);
  // head = insertAtk(head,12,3);
  head = insertBeforeValue(head,12,4);
  Node* temp = head;
  while (temp)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  
  return 0;
}
