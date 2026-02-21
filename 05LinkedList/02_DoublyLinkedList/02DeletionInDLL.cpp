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

Node* creaate2Dll(vector<int>&a){
  Node* head = new Node(a[0]);
  Node* prev = head;
  for (int i = 1; i < a.size(); i++)
  {
    Node* temp = new Node(a[i]);
    prev->next = temp;
    temp->back = prev;
    prev = temp;
  }
  return head;
}

// void print(Node* head){
//   while(head){
//     cout<<head->data<<" ";
//     head = head->next;
//   }
// }

// deletion at begining 
Node* deletehead(Node* head){
  if(head == NULL || head->next == NULL) return NULL; 
  Node* prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;

  delete prev;
  return head;
}

// deletion at end
Node* deleteTail(Node* head){
  if(head == NULL || head->next==NULL) return NULL;
  // Find the tail
  Node* tail = head;
  while(tail->next){
    tail = tail->next;
  }
  // second last node
  Node* newTail = tail->back;
  newTail->next = nullptr;
  tail->back = nullptr;
  delete tail;
  return head;
}

// delete at Kth node
 Node* removeKthElem(Node* head,int k){
  if(head==NULL){
    return NULL;
  }
  int cnt =0;
  Node* kNode=head;
  while(kNode){
    cnt++;
    if(cnt == k) break;
    kNode = kNode->next;
  }
  Node* prev = kNode->back;
  Node* front = kNode->next;
  //if only one node present
  if(prev == NULL && front == NULL){
    return NULL;
  }//delete head
  else if(prev == NULL){
    return deletehead(head);
  }
  //delete  tail
  else if(front == NULL){
    return deleteTail(head);
  }
  // delete middle node
  prev->next = front;
  front->back = prev;

  kNode->next = nullptr;
  kNode->back = nullptr;
  delete kNode;
  return head;
}

void deleteNode(Node* temp){
  Node* prev = temp->back;
  Node* front = temp-> next;
  if(front == NULL){
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
  }
  prev->next= front;
  front->back =prev;

  temp->next = temp->back = nullptr;
  free(temp);
}


int main(){
  vector<int> a = {2,4,7,1};
  Node* head = creaate2Dll(a);
  // head = deletehead(head);
  // head = deleteTail(head);
  
  // head = removeKthElem(head,2); 
  deleteNode(head->next);
  Node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;//storing value of temp node
  }
  return 0;
