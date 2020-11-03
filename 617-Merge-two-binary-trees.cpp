/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL) return t2;
        if(t2==NULL) return t1;
        TreeNode* root = new TreeNode(t1->val+t2->val);
        if(t1->left!=NULL && t2->left!=NULL){
            root->left = mergeTrees(t1->left, t2->left);
        }
        if(t1->right!=NULL && t2->right!=NULL){
            root->right = mergeTrees(t1->right, t2->right);
        }
        if(t1->left==NULL&&t2->left!=NULL){
            root->left = mergeTrees(NULL, t2->left);
        }
        if(t1->left!=NULL&&t2->left==NULL){
            root->left = mergeTrees(t1->left, NULL);
        }
        if(t1->right==NULL&& t2->right!=NULL){
            root->right = mergeTrees(NULL, t2->right);
        }
        if(t1->right!=NULL&& t2->right==NULL){
            root->right = mergeTrees(t1->right, NULL);
        }
        return root;
    }
};
