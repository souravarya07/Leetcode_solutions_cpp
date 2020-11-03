#include<iostream>
#include<map>
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

void Level_order(Node *root, map<int, vector<int>>&m, int dist){
  if(root==NULL) return;
  m[dist].push_back(root->data);
  Level_order(root->left, m, dist+1);
  Level_order(root->right, m, dist+1);
}

int findMax(Node *root){
  map<int, vector<int>>m;
  int ans = 0;
  int max_val = INT_MIN;
  Level_order(root, m, 0);
  for(auto i=m.begin();i!=m.end();i++){
    ans = i->second.size();
    max_val = max(max_val, ans);
  }
  return max_val;
}

int main(){
  Node *root = NULL;
  root = buildTree();
  PrintTree(root);
  cout<<endl;
  cout<<"Level with maximum Nodes is: "<<findMax(root)<<endl;
  return 0;
}
