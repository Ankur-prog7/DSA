#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  string data;
  Node* next;
  Node* back;
  Node(): data(0),next(nullptr),back(nullptr){};
  Node(string x):data(x),next(nullptr),back(nullptr){}
  Node(string x,Node* next,Node* random):data(x),next(next),back(random){};
};

class Browser{
  Node* currentPage;
  public:
  Browser(string &homepage){
    currentPage = new Node(homepage);
  }

  void visit(string &url){
    Node* newNode = new Node(url);
    currentPage->next = newNode;
    newNode->back = currentPage;
    currentPage = newNode;

  }
  string back(int steps){
    while(steps){
      if(currentPage->back){
        currentPage = currentPage->back;
      }else break;
    }
    return currentPage->data;
  }

  string forward(int steps){
    while(steps){
      if(currentPage->next) currentPage = currentPage->next;
      else break;
      steps--;
    }
    return currentPage->data;
  }

};


