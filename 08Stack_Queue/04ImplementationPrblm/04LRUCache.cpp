#include <bits/stdc++.h>
using namespace std;

class LRUCache{
public:
  // Doubly LL node class
  class Node{
  public:
    int key;
    int val;
    Node* next;
    Node* prev;
    // constructor to initalize node
    Node(int _key,int _val){
      key = _key;
      val = _val;
    }
  };

  // Head , tail Dummy Node
  Node* head = new Node(-1,-1);
  Node* tail = new Node(-1,-1);

  // capacity of cache
  int cap;
  
  // hash map to store key-node mapping
  unordered_map<int,Node*>m;

  // constructor to initalise LRU cache
  LRUCache(int capacity){
    cap = capacity;
    head->next = tail ;
    tail->prev = head;
  }
  // function to add a node right after head
  void addNode(Node* newNode){
    Node* temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
  }

  // funcn to remove a give node from list
  void deleteNode(Node* delNode){
    Node* delPrev = delNode->prev;
    Node* delNext = delNode->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
  }

  // funcn to get value from cache
  int get(int key_){
    // if key exists in cache
    if(m.find(key_) != m.end()){
      Node* resNode = m[key_];
      int res = resNode->val;
      // remove old mapping
      m.erase(key_);
      // Move accessed node to front
      deleteNode(resNode);
      addNode(resNode);

      // update map
      m[key_] = head->next;
      return res;
    }
    // if not found
    return -1;
  }

  // function to put key-value into cache
  void put(int key_,int value){
    // if key already exists
    if(m.find(key_) != m.end()){
      Node* existingNode = m[key_];
      m.erase(key_);
      deleteNode(existingNode);
    }
    // if capa reached
    if(m.size() == cap){
      m.erase(tail->prev->key);
      deleteNode(tail->prev);
    }
    // insert new node at first
    addNode(new Node(key_,value));
    m[key_] = head->next;
  }
};