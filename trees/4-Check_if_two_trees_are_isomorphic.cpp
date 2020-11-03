#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

Node *buildTree(){
  int d;
  cin>>d;
  if(d==-1) return NULL;
  Node *n = new  Node(d);
  n->left = buildTree();
  n->right = buildTree();
}

void PrintTree(Node *root){
  if(root==NULL) return;
  cout<<root->data<<"->";
  PrintTree(root->left);
  PrintTree(root->right);
}

bool isIsomorphic(Node *root1, Node *root2){
  if(root1==NULL && root2==NULL) return true;
  if(root1==NULL||root2==NULL) return false;
  if(root1->data!=root2->data) return false;
  if(isIsomorphic(root1->left, root2->left)&&isIsomorphic(root1->right, root2->right)||isIsomorphic(root1->left, root2->right)&&isIsomorphic(root1->right, root2->left)){
    return true;
  }
}

int main(){
  Node *root1 = NULL;
  Node *root2 = NULL;
  root1 = buildTree();
  root2 = buildTree();

  PrintTree(root1);
  cout<<endl;
  PrintTree(root2);
  cout<<endl;
  if(isIsomorphic(root1, root2)){
    cout<<"Trees are Isomorphic"<<endl;
  }
  else{
    cout<<"Trees are not Isomorphic"<<endl;
  }
  return 0;
}
