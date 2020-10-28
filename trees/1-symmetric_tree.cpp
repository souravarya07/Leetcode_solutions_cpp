#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node *left = NULL;
  Node *right = NULL;

  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};

Node* buildTree(){
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

bool isSymmetric(Node *root){
  if(root==NULL) return true;
  if(!root->left && !root->right) return true;
  Node *leftroot;
  Node *rightroot;
  queue<Node*> q;
  q.push(root);
  q.push(root);
  while(!q.empty()){
    leftroot = q.front();
    q.pop();
    rightroot = q.front();
    q.pop();
    if(leftroot->data!=rightroot->data) return false;
    if(leftroot->left && rightroot->right){
      q.push(leftroot->left);
      q.push(rightroot->right);
    }
    else if(leftroot->left||rightroot->right) return false;

    if(leftroot->right && rightroot->left){
      q.push(leftroot->right);
      q.push(rightroot->left);
    }
    else if(leftroot->right||rightroot->left){
      return false;
    }
  }
  return true;
}

int main(){
  Node *root = NULL;
  root = buildTree();
  PrintTree(root);
  if(isSymmetric(root)){
    cout<<"Yes, the tree is symmetric"<<endl;
  }
  else{
    cout<<"No the tree is not symmetric"<<endl;
  }
  return 0;
}
