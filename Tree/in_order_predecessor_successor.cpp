#include<bits/stdc++.h>
using namespace std ;

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
 void create_BST(node* root ; int value ){
   if(root == NULL){
    root = new node(value);
    return  ;
   }
   if(root -> data > value)
     create_BST(root -> left , value);
   else
     create_BST(root -> right , value);
}

void takeinput(node* &root){
  int val ;
  cin>> val ;
  while(val != -1){
    create_BST(root , val);
    cin>> val;
  }
}
vector<int> in_order(node* root){
  vector <int > a;
  if(root == NULL)
     return NULL;
  in_order(root -> left);
  a.push_back(root -> data);
  in_order(root -> right);

  return a;
}
void predecessor(node* root , int value){
   if(root == NULL)
     return ;
   vector<int> result = in_order(root);
   for(int i = 0 ; i< result.size() ; i++){
      if(reslt[i] == value){
        cout<<"Predecessor: "<<result[i-1]<<endl;
         cout<<"Successor: "<<result[i+1]<<endl;
      }

   }


}
int main(){
 node* root = NULL;

 cout<<" Enter the value of BST: \n";
 takeinput(root);
 int val;
 cin>> val;
 predecessor(root , val);

}
