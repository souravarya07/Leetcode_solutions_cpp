#include<iostream>
#include<bits/stdc++.h>
#include<map>
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

void DiagonalValue(Node *root, map<int, int> &m, int ht){
  if(root==NULL) return;
  m[ht] = root->data + m[ht];
  DiagonalValue(root->left, m, ht+1);
  DiagonalValue(root->right, m, ht);
}

vector<int> DiagonalSum(Node *root){
  int ht = 0;
  map<int, int> m;
  vector<int> v;
  DiagonalValue(root, m, ht);
  for(auto i=m.begin();i!=m.end();i++){
    v.push_back(i->second);
  }
  return v;
}



int main(){
  Node *root = NULL;
  root = buildTree();
  PrintTree(root);
  cout<<"\n";
  vector<int> v = DiagonalSum(root);

  for(auto i:v) cout<<i<<" ";
  return 0;
}
