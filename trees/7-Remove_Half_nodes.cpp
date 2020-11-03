#include<iostream>
#include<bits/stdc++.h>
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

Node *removeHalfNodes(Node *root){
  if(root==NULL) return NULL;
  root->left = removeHalfNodes(root->left);
  root->right = removeHalfNodes(root->right);
  if(root->left==NULL && root->right!=NULL){
    Node *temp = root->right;
    delete root;
    return temp;
  }
  if(root->left!=NULL && root->right==NULL){
    Node *temp = root->left;
    delete root;
    return temp;
  }
  return root;
}

int main(){
  Node *root = NULL;
  root = buildTree();
  cout<<"\n";
  PrintTree(root);
  cout<<"\n";
  Node *temp = removeHalfNodes(root);
  PrintTree(temp);
}
