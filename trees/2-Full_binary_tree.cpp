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
  if(d ==-1) return NULL;
  Node *n = new Node(d);
  n->left = buildTree();
  n->right = buildTree();
}

void PrintTree(Node *root){
  if(root==NULL) return;
  cout<<root->data<<"->";
  PrintTree(root->left);
  PrintTree(root->right);
}

bool isFullBinary(Node *root){
  if(root==NULL) return true;
  else if(root->left==NULL && root->right==NULL) return true;
  else if(root->left==NULL && root->right!=NULL) return false;
  else if(root->left!=NULL && root->right == NULL) return false;

  return isFullBinary(root->left)&&isFullBinary(root->right);
}

int main(){
  Node *root= NULL;
  root = buildTree();
  PrintTree(root);
  cout<<endl;
  if(isFullBinary(root)){
    cout<<"It is a Full binary tree"<<endl;
  }
  else{
    cout<<"It is not a full binary tree"<<endl;
  }
  return 0;
}
