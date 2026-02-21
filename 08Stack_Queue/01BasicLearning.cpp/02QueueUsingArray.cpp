// implement q using array
#include<bits/stdc++.h>
using namespace std;

class QueueUsingArray{
  int q[10];  
  int size = sizeof(q)/sizeof(q[0]);
  int CurrSize =0;
  int start =-1 , end =-1;

  void push(int x){
    if(CurrSize == size){
      cout<<"Queue is Full\n";
      return;
    } 
    // First element being inserted
    if(CurrSize == 0) {
      start = 0, end =0;
    }
    else end = (end+1)%size;//circular increement in normal queue we do q++;
    q[end] = x;
    CurrSize++;
  }

  int pop(){
    if(CurrSize==0) {
      cout << "Empty Queue";
      return -1;
    }
    int el = q[start];
    if(CurrSize == 1) start = end =-1;
    else start = (start+1)%size;
    CurrSize --;
    return el;
  }

  int top(){
  if(CurrSize==0) {
  cout<<"Queue is Empty";
  return;
  }
  return q[start];
  }

  int size(){
    return q[CurrSize];
  }
};
