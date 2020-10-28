#include <iostream>
#include <map>
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

void vop(Node *root, map<int,vector<int>> &m, int dist){
  if(root==NULL) return;
  m[dist].push_back(root->data);
  vop(root->left, m, dist-1);
  vop(root->right, m, dist+1);
}

vector<int> verticalSum(Node *root){
  vector<int> final_sum;
  int sum = 0;
  map<int, vector<int>> m;
  vop(root, m, 0);
  for(auto i=m.begin();i!=m.end();i++){
    for(auto j=0;j<i->second.size();i++){
      sum += i->second[j];
    }
    final_sum.push_back(sum);
    sum = 0;
  }
  return final_sum;
}

int main(){
  Node *root = NULL;
  root = buildTree();
  PrintTree(root);
  cout<<endl;
  cout<<"Vertical Sum :"<<endl;
  vector<int> res = verticalSum(root);
  for(int i:res) cout<< i <<" ";
  cout<<endl;
  return 0;
}
