#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;

  node(int value)
  {
    this->data = value;
    this->left = NULL;
    this->right = NULL;
  }
};


node *create_tree(node *root)
{
  int value;
  cout << "Enter the value: \n";
  cin >> value;
  if (value == -1)
    return NULL;
  root = new node(value);
  cout << "Left node of " << value << endl;
  root->left = create_tree(root);
  cout << "Right node of " << value << endl;
  root->right =create_tree(root);

  return root;
}


void level_wise(node* root)
{
  queue<node *> q;
  if (root == nullptr)
    return;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();
    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left != NULL)
      {
        q.push(temp->left);
      }
      if (temp->right != NULL)
        q.push(temp->right);
    }
  }
}

pair < bool , int > sum_tree(node* root){

   if( root == NULL ){
    pair < bool , int > p = make_pair(true , 0);
    return p ;
   }
   // for leaf node
   if ( root -> left == NULL && root -> right == NULL ){
    pair < bool , int > p = make_pair(true , root -> data);
    return p ;
   }

   pair < bool , int > leftSubTree = sum_tree(root -> left);
   pair < bool , int > RightSubTree = sum_tree(root -> right);

   bool left_side = leftSubTree.first;
   bool right_side = RightSubTree.first;

   bool val = root -> data = leftSubTree.second = RightSubTree.second ;

   pair < bool , int > ans;

   if(left_side && right_side && val ){
      ans.first = true ;
    //  ans .second = root -> data + left + right;
      ans.second = 2*root -> data;
   }else
     ans.first = false;

  return ans;
}

int main(){
  node* root = NULL;

  root = create_tree(root);

  level_wise(root);

  pair < bool , int > result = sum_tree(root);
  if(result.first)
    cout<<"Its a sum tree\n";
  else
    cout<<"Its not a sum tree\n";

}
