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
    int levels(TreeNode* root){ //for finding the levels of the particular node
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void pre(TreeNode* root,int &ans){
        if(root==NULL) return ;
        ans=max(ans,levels(root->left)+levels(root->right));
        pre(root->left,ans);
        pre(root->right,ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=-1;
        pre(root,ans);
        return ans;
    }
};