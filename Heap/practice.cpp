#include<bits/stdc++.h>
using namespace std ;

class heap{
  public:
    int heap_size ;
    int arr[100];

    heap(){
      heap_size = 0 ;
      arr[0] = -1; 
    }
   void heap_insert(int value){
      heap_size++;
      int index = heap_size;
      arr[index] = value ;

      while(index > 1){
         int parents = index/2 ;
         if(arr[parents] < arr[index]){
            swap(arr[parents] , arr[index]);
            index = parents ;
         }else 
            return ;
      }
   }

   void heap_delete(){
      if(heap_size == 0 ){
         cout<<"Heap is empty \n";
         return;
      }
      int index = 1 ;
      swap(arr[heap_size] , arr[index]);
      heap_size--;

      int left_index = index*2 ;
      int right_index = index*2 + 1;

      while(index < heap_size){

         if(left_index < heap_size && arr[index] < arr[left_index]){
            swap(arr[left_index] , arr[index]);
            index = left_index;
         }else if(right_index < heap_size && arr[index] < arr[right_index]){
            swap(arr[right_index] , arr[index]);
            index = right_index;
         }else
            return ;
            
      }
   }

   void heap_print(){
      for (int i = 1 ; i <= heap_size ; i++)
         cout<<arr[i]<<" ";
      cout<<endl;
   }
   
};

void print(int arr[] , int heap_size){
      

      for(int i = 1 ; i <= heap_size ; i++){
         cout<<arr[i]<<" ";
      }
      cout<<endl;
}

void heapify(int arr[] , int heap_size  , int current_index){
   int largest = current_index ;
   int left_index = current_index*2 ;
   int right_index = current_index*2 + 1;

   while(largest < heap_size){
      if(left_index <= heap_size && arr[left_index] > arr[largest])
        largest = left_index;
      if(right_index <=  heap_size && arr[right_index] > arr[largest])
        largest = right_index;

      if(largest != current_index){
         swap(arr[largest] , arr[current_index]);
         heapify(arr , heap_size , largest);
      } 
   }
}

int main(){
   int arr[6] = {-1 , 5, 7 , 9 , 2, 16};
   int n = 5;
   for(int i = n/2 ; i> 0 ; i-- )
      heapify(arr , n , i);
   for(int i = 1 ; i <= n ; i++ )
     cout<<arr[i]<<" ";
}