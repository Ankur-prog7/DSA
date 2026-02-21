#include<bits/stdc++.h>
using namespace std;
 
class Node
{
public:
  int data;
  Node* next;
public:
  Node(int data1,Node* next1){
    data = data1;
    next = next1;
  }
public:
  Node(int data1){
    data=data1;
    next = nullptr;
  }  
};

// creating node
Node* createNode(vector<int>&a){
  Node* head = new Node(a[0]);
  Node* mover = head;
  for (int i = 1; i < a.size(); i++)
  {
    Node* temp = new Node(a[i]);
    mover->next = temp;
    mover=temp;
  }
  return head;
}

// deleting head node
Node* removeHead(Node* head){
  if(head==NULL) return head;
  Node* temp = head;
  head=head->next;
  delete temp;
  return head;
}

//node tail remover
Node* removeTail(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* temp = head;
  while(temp->next->next){
    temp=temp->next;
  }
  free(temp->next);
  temp->next = nullptr;

  return head;
}

// delete kth elem in LL
Node* removeK(Node* head,int k){
  if(head == NULL) return head;
  if(k==1){
    Node*temp = head;
    head= head->next;
    free(temp);
    return head;
  }
  int cnt=1;
  Node* temp = head;
  Node* prev = NULL;
  while (temp)
  {
    if(cnt == k){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
    cnt++;
  }
  return head;
}

// delete elem of LL
Node* removeEl(Node* head,int el){
  if(head == NULL) return head;
  if(head->data == el){
    Node*temp = head;
    head= head->next;
    free(temp);
    return head;
  }
  
  Node* temp = head;
  Node* prev = NULL;
  while (temp)
  {
    if(temp->data == el){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
    
  }
  return head;
}


int main(){
  vector<int>a = {12,5,8,3};
  Node* head = createNode(a);
  // head = removeHead(head);
  // head = removeTail(head);
  // int k = 2;
  // head= removeK(head,k);
  int k = 8;
  head =  removeEl(head,k);
  Node* temp = head;
  while(temp){
    cout<< temp->data <<" ";
    temp = temp->next;
  }
  return 0 ;
}