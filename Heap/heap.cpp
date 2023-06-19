#include<bits/stdc++.h>

using namespace std ;

class heap{
 public :
   int size_heap ;
   int arr[100];

   heap(){
      size_heap = 0 ;
      arr[0] = -1 ;
   }

   void insert_heap(int x){
      size_heap = size_heap + 1;
      int index = size_heap ;
      arr[index] = x;
    
     
     while(index > 1){
        int parents = index/2 ;
        if(arr[parents] >  arr[index]){
           swap(arr[index] , arr[parents]);
           index = parents;
        }else 
           return ;
     }
   }

   void print_heap(){
      
      if(size_heap == 0){
        cout<<"Heap is empty!\n";
        return ;
      }
      
      for(int i = 1 ; i <= size_heap ; i++){
          cout<<arr[i] <<" ";
   }
   }
   //Delete the root 
   void delete_heap(){
      
      if(size_heap == 0){
        cout<<"Heap is empty!\n";
        return ;
      }
      
      //swap the root with last element then dicrease the size
      swap(arr[1] , arr[size_heap]);
      size_heap-- ;
      
      int index = 1 ;
      
      //repositioning the root on its write position
      while(index < size_heap){
         
         int leftIndex = 2* index ;
         int rightIndex = 2* index + 1 ;

         if(leftIndex < size_heap && arr[index] < arr[leftIndex]){
            swap(arr[index] , arr[leftIndex]);
            index = leftIndex;
         }else if(rightIndex < size_heap && arr[index] < arr[rightIndex]){
           swap(arr[index] , arr[rightIndex]);
            index = rightIndex; 
         }else 
            return ;

      }
   }
  
};

int main(){
    heap h ;
    h.insert_heap(2);
    h.insert_heap(5);
    h.insert_heap(10);
    h.print_heap();

    h.delete_heap();
    cout<<endl;
    h.print_heap();
}