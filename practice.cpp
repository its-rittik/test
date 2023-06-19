#include<bits/stdc++.h>
using namespace std;

class heap{
  public:
     int arr[100];
     int heap_size ;

     heap(){
      arr[0] = -1;
      heap_size = 0;
     }

     void heap_insart(int value){
        heap_size++;
        int index = heap_size ;
        arr[index] = value;

        while(index > 1){
           int parent = index/2 ;

           if(arr[parent]<arr[index]){
              swap(arr[parent ] , arr[index]);
              index = parent ;
           }else
             return;
        }
     }

     void print(){
        for(int i = 1 ; i <= heap_size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }

     void heap_delete(){

        if(heap_size == 0){
            cout<<"Heap is empty!!\n";
            return;
        }

        arr[1] = arr[heap_size];
        heap_size--;
        int index = 1 ;
        while(index < heap_size){
            int leftIndex = 2*index ;
            int rightIndex = 2*index + 1;

            if(leftIndex < heap_size && arr[index] < arr[leftIndex]  ){
                swap(arr[leftIndex] , arr[index]);
                index = leftIndex ;
            }

            else if(rightIndex < heap_size && arr[index] < arr[rightIndex]  ){
                 swap(arr[rightIndex] , arr[index]);
                 index = rightIndex;
         } else
            return ;
        }

     }
};

int main(){
  heap h ;

  h.heap_insart(50);
  h.heap_insart(55);
  h.heap_insart(53);
  h.heap_insart(52);
  h.heap_insart(54);
  //h.heap_insart(12);

  h.print();

  h.heap_delete();

  h.print();

  h.heap_delete();

  h.print();

  h.heap_delete();

  h.print();
}
