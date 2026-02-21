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

Node* mergeKLists(vector<Node*> &listArray){

  // create min heap
  priority_queue<pair<int,Node*>,
  vector<pair<int ,Node*>> ,
  greater<pair<int,Node*>>>pq;

  // Push the first node of each list
  for (int i = 0; i < listArray.size(); i++)
  {
   if(listArray[i]){
    pq.push({listArray[i]->data,listArray[i]});
   }
  }

  // Create dummy node
  Node* dummyNode = new Node(-1);
  Node* temp = dummyNode;


  while(!pq.empty()){//Process until PQ becomes empty

    // Pick the smallest node
    auto it = pq.top();
    pq.pop();

    // Push the next node of the popped node
    if(it.second->next)
      pq.push({it.second->next->data,it.second->next});

    // Attach this smallest node to our new list
    temp->next = it.second;
    temp=temp->next;  
  }
  return dummyNode->next;
} 