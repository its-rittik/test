#include<bits/stdc++.h>
using namespace std ;

class node{
 public:
     int data ;
     node* left ;
     node*right ;

     node(int value ){
       this -> data = value;
       this -> left = NULL;
       this -> right = NULL;
     }
};

node* create_tree(node* root){

  cout<<"Enter the value :\n";
  int value ;
  cin>> value ;

  if(value == -1)
      return NULL;

  root = new node(value);

  cout<<"left node of "<<value<<" will be... ";
  root -> left = create_tree(root);

  cout<<"Right node of "<<value<<" will be... ";
  root -> right = create_tree(root);

  return root;
}

void level_wise(node* root){
     queue <node*> q;

     if(root == NULL)
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
        }else{
         cout<<temp -> data <<" ";

         if(temp -> left != NULL)
            q.push(temp -> left );
         if(temp -> right != NULL)
            q.push(temp -> right);
        }
     }
}

int height(node*root){

   if(root == NULL)
     return 0;

   int left = height(root -> left);
   int right = height(root -> right);

   int ans = max(left , right ) + 1 ;

   return ans ;
}

bool balance(node* root){
   if(root == NULL)
     return true ;

   bool left =  balance(root -> left); //1st condition
   bool right = balance(root -> right); //2nd condition

   int height_diff = abs(height(root -> left)- height(root -> right));

   if( left && right && height_diff<=1)
      return true ;
   else
      return false;
}

 pair<bool , int > balance_faster(node* root){
   if(root == NULL){
      pair<bool , int> p =  make_pair(true , 0 );
      return p ;
   }
    pair<bool , int > left_side = balance_faster (root -> left);
    pair<bool , int > right_side = balance_faster(root -> right);

    bool left = left_side.first;
    bool right = right_side.first;

    int height_dif = abs(left_side.second - right_side.second);

    pair<bool , int > answer;
    answer.second = max(left_side.second , right_side.second) + 1 ;

    if(left && right && height_dif<=1)
       answer.first = true;
    else
       answer.first = false;

   return answer;
 }

int main(){
   node* root = NULL;
   root = create_tree(root);
   level_wise(root);

   cout<<"Height of the tree\n";
   cout<<height(root)<<endl;

   if(balance(root))
     cout<<"Its balanced\n";
   else
     cout<<"Sorry ! its not balanced\n";

   pair<bool , int> result =balance_faster(root);

   if(result.first)
     cout<<"Its balanced\n";
   else
     cout<<"Sorry ! its not balanced\n";

   cout<<result.second<<endl;
}
