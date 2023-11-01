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
    int dia(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(dia(root->left),dia(root->right));
    }
    void pre(TreeNode* root,int &ans){
        if(root==NULL) return ;
        ans=max(ans,dia(root->left)+dia(root->right));
        pre(root->left,ans);
        pre(root->right,ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=-1;
        pre(root,ans);
        return ans;
    }
};