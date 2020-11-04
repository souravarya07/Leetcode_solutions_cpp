/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==NULL) return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        Node *curr = NULL;
        while(!stk.empty()){
            curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            for(auto itr=curr->children.begin();itr!=curr->children.end();itr++){
                stk.push(*itr);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
