#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* back;
  Node* next;
public:
  Node(int data1,Node* back1,Node* next1){
    data=data1;
    back = back1;
    next = next1;
  }
public:
  Node(int data1){
    data = data1;
    back = nullptr;
    next = nullptr;
  }
};

Node* createNode(vector<int>&a){
  Node* head = new Node(a[0]);
  Node* prev = head;
  for (int i = 1; i < a.size(); i++)
  {
    Node* temp = new Node(a[i]);
    prev->next=temp;//link prev to temp
    temp-> back = prev;
    prev = temp;
  }
  return head;
}

// insert before head of 2Dll
Node* insertBeforeHead(Node* head, int val){
  Node* newHead = new Node(val,nullptr,head);
  head->back=newHead;

  return newHead;
}

// insert before tail of 2DLL
Node* insertBeforeTail(Node* head,int val){
  if(head->next==NULL){
    return insertBeforeHead(head,val);
  }
  Node* tail = head;
  while(tail->next){//tail->next!= NULL
    tail = tail->next;//tail will point to tail->next is pointing
  }
  Node* prev = tail->back;
  Node* newNode = new Node(val,prev,tail);
  prev->next = newNode;
  tail->back = newNode;
  return head;
}

Node* insertBeforekthElem(Node* head,int k,int val){
  if(k==1){
    return insertBeforeHead(head,val);
  }
  Node* temp = head;
  int cnt = 0;
  while(temp){
    temp=temp->next;
    cnt++;
    if(cnt==k) break;
  }
  Node* prev = temp->back;//prev and temp->back are pointing to same node or prev and temp are pointing to same node
  Node* newNode = new Node(val,prev,temp);
// since here we update the prev and temp poitner
// prev->next is one link.
// tail->back is another link.
// They must both be updated separatel
  prev->next = newNode;
  temp->back = newNode;

  return head;
}

// insert Node before Kth
void insertBeforeNode(Node* node,int val){
  Node* prev = node->back;
  Node* newNode = new Node(val,prev,node);
  prev->next = newNode;
  node->back = newNode;
}

int main(){
  vector<int>a = {2,4,6,7};
  Node* head = createNode(a);
  // head = insertBeforeHead(head,3);
  // head = insertBeforeTail(head,8);
  // head = insertBeforekthElem(head,2,12);
  insertBeforeNode(head->next->next,100);
  Node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}


