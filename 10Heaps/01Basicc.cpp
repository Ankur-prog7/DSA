// max heap using array 
// 1 based indexing
#include<bits/stdc++.h>
using namespace std;

class heap{
  public:
  int arr[100];
  int size;

  heap(){ //constructor and used to initalize object
    arr[0] = -1; //dummy node
    size = 0;
  }

  void insert(int val){
    size ++ ;
    int ind = size;
    arr[ind] = val;
    while(ind > 1){
      int parent = (ind)/2;
      if(arr[parent] < arr[ind]){
        swap(arr[parent],arr[ind]);
        ind = parent; // move ind to parent 
      }
      else{
        return;
      }
    }
  }

  void printHeap() {
    for(int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deleteFromHeap(){
    if(size == 0){
      cout << "nothing to delete";
      return;
    }

    arr[1] = arr[size]; // repace root node to leaf node
    size--;

    // take root node to its correct position
    int i = 0 ; 
    while(i<size){
      int lind = 2*i;
      int rind = 2*i;

      if(lind <= size && arr[i]<arr[lind]){
        swap(arr[i],arr[lind]);
        i = lind;
      }
      else if (rind <= size && arr[i]<arr[rind]){
        swap(arr[i],arr[rind]);
        i = rind;
      }
      else return; 
    }
  }


  // Heapify
  void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1; 

    if( left < n && arr[largest] < arr[left]){
      largest = left;
    }
    if( right < n && arr[largest] < arr[right]){
      largest = right;
    }

    if(largest != i){
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest);
    }

  }
  void buildHeap(int arr[],int n){
    for(int i = n/2;i>=1;i--){
      heapify(arr,n,i);
    }
  }


  // heap sort
  void heapSort(int arr[],int n){
    int size = n;
    while(size > 1){
      // step 1 swap
      swap(arr[size],arr[1]);
      size--;

      // step 2
      buildHeap(arr,size);
    }
  }
};

int main(){
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  
  h.printHeap();
  return 0;
}