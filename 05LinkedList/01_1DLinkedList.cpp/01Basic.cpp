
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
//Used when you want to create a node and immediately set its next pointer 
public:
  Node(int data1,Node* next1){
    data = data1;
    next = next1;
  }
// to create a standalone node whose next is nullptr
// next is automatically nullptr because of the constructor
public:
Node(int data1){
  data = data1;
  next = nullptr;
}
};

Node* convertArr2LL(vector<int>&a){
  // Create the head node
  // Node* is used coz it will point entire NOde,if we have written int* then head will only point to integer value
  Node* head = new Node(a[0]);
  // Have a mover pointer
  Node* mover = head;

  for(int i=1;i<a.size();i++){//start loop from 1 coz 1 node is already created
    // Create new node in each iteration
    Node* temp = new Node(a[i]);
    // Attach new node to the list
    mover->next = temp;
    // Move the mover forward
    mover = temp;
  }
  return head;
}

//Searching in LL
int Search(Node* head,int val){
  Node* temp = head;
  while(temp){
    if(temp->data == val) return 1;
    temp = temp->next;
  }
  return 0;
}

//Length of LL
int lengthOfLL(Node* head){
  int cnt =0;
  Node* temp = head;
  while(temp){
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

int main(){
  vector<int> a = {2,5,8,4};
  Node* head = convertArr2LL(a);
  // cout<< head->data;

  // for traversing
  // Node* temp = head;//so we always have head of ll
  // while (temp) // // shorthand of temp != NULL
  // {
    // cout<<temp->data<<" ";
    // temp = temp->next;
  // }

  // search
  cout<< Search(head,14);//return 0 or false


  // length
  cout<<lengthOfLL(head);
}