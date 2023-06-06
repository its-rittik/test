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

node *create_level_wise(node *root2)
{
  queue<node *> q;

  int value;
  cout << "Enter the root: \n";
  cin >> value;
  if (value == -1)
    return NULL;
  root2 = new node(value);
  q.push(root2);

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
  return root2;
}

bool identical_tree(node* root , node* root2){
  if(root == NULL && root2 == NULL)
     return true ;
  if(root != NULL && root2 == NULL)
     return false;
  if(root == NULL && root != NULL)
     return false;

  bool left = identical_tree(root -> left , root2 -> left);
  bool right = identical_tree(root -> right , root2 -> right);

  int value = root -> data - root2 -> data ;

  if(left && right && value == 0)
     return true ;
  else
     return false;
}

int main(){

  node* root = NULL ;
  node* root2 = NULL;

  root = normal_way(root);
  root2 = create_level_wise(root);

  if(identical_tree(root , root2))
      cout<<"Its identical\n";
  else
      cout<<"Its not identical\n";
}
