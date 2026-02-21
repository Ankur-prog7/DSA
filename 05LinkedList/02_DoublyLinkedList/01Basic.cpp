#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node* back;
public:
  Node(int data1,Node* next1,Node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
public:
  Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
  }  
};

Node* createArr2DLL(vector<int>&a){
  Node* head = new Node(a[0]);
  Node* prev = head;
  for (int i = 1; i < a.size(); i++)
  {
    Node* temp = new Node(a[i],nullptr,prev);
    prev->next = temp;//link krr rhw prev ke next ko temp se or prev ke next me temp ka daddress store krr rhe
    temp->back = prev;
    prev = temp;
  }
  return head;
}

void print(Node* head){
  while(head){
    cout<< head->data<<" ";
    head = head->next;
  }
}

int main(){
  vector<int>a = {2,4,3,1};
  Node* head = createArr2DLL(a);
  print(head);
  return 0;
}