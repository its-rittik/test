#include<bits/stdc++.h>
using namespace std;

 class node{
 public:
    int data ;
    node* left ;
    node* right;

    node(int value){
      this -> data = value ;
      this -> left = NULL;
      this -> right = NULL;
    }
};
void print(node* root){
 queue <node*> q;
 if(root == nullptr)
     return ;
 q.push(root);
 q.push(NULL);
 while(!q.empty()){
    node* temp = q.front();
    q.pop();

    if(temp == NULL){
        if(!q.empty())
            q.push(NULL);
        cout<<endl;
    }
    else{
     cout<<temp -> data<<" ";
     if( temp -> left != NULL )
         q.push(temp -> left);
     if(temp -> right != NULL)
        q.push(temp -> right);

    }

 }
}
int minimum( node* root){
  if(root == NULL)
     return -1 ;
  node* temp = root ;
  while(temp -> left != NULL){
    temp = temp -> left;
  }
  return temp -> data ;
}
void create_BST(node* &root , int value){
  if(root == nullptr){
    root = new node(value);
    return ;
  }
  if(root -> data > value)
    create_BST(root -> left , value );
  else
    create_BST( root -> right , value);
}

void take_input(node* & root){
  int val;
  cout<<"Enter the input data :\n";
  cin>> val ;
  while(val!= -1){
    create_BST(root , val);
    cin>> val ;
  }
}
node* delete_BST(node* root , int x){
  //base case
  if(root == NULL)
    return NULL ;
  //base case
  if(root -> data == x){
    //0 child
    if(root -> left == NULL && root -> right == NULL){
        delete root ;
        return NULL;
    }

    //1 child
      //for only left child
     if(root -> left != NULL && root -> right == NULL){
        node* temp = root -> left ;
        delete root -> left ;
        return temp;
     }
      // for only right child
      if(root -> left == NULL && root -> right != NULL){
        node* temp = root -> right ;
        delete root -> right ;
        return temp;
     }

    //2 child
     if(root -> left != NULL && root -> right != NULL){
        // using option 2 but option 1 can be used also
        int mini = minimum(root -> right);
        root -> data = mini ;
        root -> right = delete_BST(root -> right , mini );
        return root ;
     }
  }
  if(root -> data > x )
    root -> left = delete_BST(root -> left , x);
  else
    root -> right = delete_BST(root -> right , x);
}
int main(){
   node* root = NULL;
   take_input(root);
   print(root);
   cout<<"Which element want to delete :"<<endl;\
   int x ;
   cin>> x ;
   delete_BST(root , x);
   cout<<"\nNew tree:\n";
   print(root);
   //100 50 150 25 60 110 180 10 30 105 120 170 200 5 15 -1

}
