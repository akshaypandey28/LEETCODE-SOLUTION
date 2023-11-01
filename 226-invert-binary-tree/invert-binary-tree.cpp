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
    TreeNode* mirror(TreeNode* root){
        if(root==NULL) return root;
        swap(root->left,root->right); //har node pr jake unko swap krna hai aur ye traversal 
        // se kiya ja skta hai
        mirror(root->left);
        mirror(root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return mirror(root);
    }
};