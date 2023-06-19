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

node *normal_way(node *root)
{
  int value;
  cout << "Enter the value: \n";
  cin >> value;
  if (value == -1)
    return NULL;
  root = new node(value);
  cout << "Left node of " << value << endl;
  root->left = normal_way(root);
  cout << "Right node of " << value << endl;
  root->right = normal_way(root);

  return root;
}

node *create_level_wise(node *root)
{
  queue<node *> q;

  int value;
  cout << "Enter the root: \n";
  cin >> value;
  if (value == -1)
    return NULL;
  root = new node(value);
  q.push(root);

  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();
    cout << "Enter left node of " << temp->data << " :\n";
    int leftdata;
    cin >> leftdata;

    if (leftdata != -1)
    {
      temp->left = new node(leftdata);
      q.push(temp->left);
    }

    cout << "Enter Right node of " << temp->data << " :\n";
    int rightdata;
    cin >> rightdata;

    if (rightdata != -1)
    {
      temp->right = new node(rightdata);
      q.push(temp->right);
    }
  }
  return root;
}
void level_wise(node *root)
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
void current_level(node* root  , int level){
   if(root == nullptr)
      return ;
   if(level == 1 ) cout<< root -> data<<" ";
   if(level > 1) {
      current_level(root -> left , level -1);
      current_level(root -> right , level -1);
   }
}

void level_wise_without_queue(int height , node* root){
   for(int i = 1 ; i <= height ; i++)
     current_level(root , i );
    cout<<endl;
}

int height(node* root){
  if(root == NULL)
      return 0 ;
  int left = height(root -> left);
  int right = height (root -> right);

  int ans = max(left , right ) + 1;

  return ans ;
}
void in_order(node* root){
  if(root == NULL)
      return ;
  in_order(root -> left);
  cout<<root -> data <<" ";
  in_order(root -> right);

}

void pre_order(node* root){
  if(root == NULL)
    return ;
  cout<<root -> data <<" ";
  pre_order(root -> left);
  pre_order(root -> right);
}

int main()
{
  node *root = NULL;
  root = create_level_wise(root);
  level_wise(root);

  int h = height(root);
  cout<<"Height: "<<h<<endl;

  cout<<"Level wise without using queue :\n";
  level_wise_without_queue( h ,root);
  cout<<"In Order: "<<endl;
  in_order(root);
  cout<<"\nPre Order: "<<endl;
  pre_order(root);
  // 1 2 3 4 5 6 7 8  -1 -1 -1 -1 -1 -1 -1 -1 -1
}
