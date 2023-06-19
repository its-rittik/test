#include<bits/stdc++.h>
using namespace std ;

class node{
  public:
      int data ;
      node* left ;
      node* right;

      node(int value){
       this -> data = value;
       this -> left = NULL;
       this -> right = NULL;
      }
};
 void create_BST(node* &root , int value){

    if(root == NULL){
        root = new node(value);
        return ;
    }
    if(value < root -> data)
        create_BST(root -> left , value);
    else
        create_BST(root -> right , value);
 }

 void takeData(node* &root){
    int value ;
    cin>>value;

    while(value != -1){
      create_BST(root , value);
      cin>>value;
    }
 }

 void traverse_level_wise(node* root){
   queue <node*> q;

   if(root == NULL)
     return ;
   q.push(root);
   q.push(NULL);

   while(!q.empty()){
     node* temp = q.front();
     q.pop();
     if(temp == NULL){
        if(!q.empty()){
            q.push(NULL);
        }
        cout<<endl;
     }else{
       cout<<temp -> data <<" ";
       if(temp -> left != NULL)
        q.push(temp -> left);
       if(temp -> right != NULL)
        q.push(temp -> right);
     }
   }
 }
 //recursivly
 void search_in_BST(node* root , int x){
    if(root == NULL){
    cout<<"Value does not exist in BST\n";
    return ;
    }
   if(root -> data == x){
     cout<<x<<" exist in BST\n";
     return ;
   }
   if(root -> data > x)
     search_in_BST(root -> left , x);
   else
      search_in_BST(root -> right , x);
 }
 //iteratively
  void serch_in_BST_iteratively(node* root , int x){
   if(root == NULL){
    cout<<"Value does not exist in BST\n";
    return ;
    }
    node* temp = root;
    while(temp != NULL){
     if(temp -> data == x){
     cout<<x<<" exist in BST\n";
     return ;
     }
     if(temp -> data > x )
        temp = temp -> left;
     else
        temp = temp -> right;
   }
   cout<<"Value does not exist in BST2\n";
  }
int main(){
 node* root = NULL;
 cout<<"Value of BST; \n";
 takeData(root);
 cout<<"Traverse level wise\n";
 traverse_level_wise(root);
 cout<<"Enter the searching value in BST\n";
 int val ;
 cin>> val;
 cout<<"Recursively :\n";
 search_in_BST(root , val);
 cout<<"Iteratively :\n";
 serch_in_BST_iteratively(root , val);

}
