#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node *left, *right;

  Node(int d){
    data = d;
    left = right = NULL;
  }
};

Node *buildTree(){
  int d;
  cin>>d;
  if(d==-1) return NULL;
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

int SumOfLeftNodes(Node *root){
  if(root == NULL) return 0;

  if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
    return root->left->data + SumOfLeftNodes(root->right);
  }
  return (SumOfLeftNodes(root->left) + SumOfLeftNodes(root->right));
}

int main(){
  Node *root =NULL;
  root =buildTree();
  PrintTree(root);
  cout<<"\n";
  cout<<SumOfLeftNodes(root)<<endl;
  return 0;
}

//1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 6 -1 -1 -1
