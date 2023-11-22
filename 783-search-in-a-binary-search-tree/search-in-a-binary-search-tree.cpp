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
    TreeNode* exist(TreeNode* root,int val){
        if(root==NULL  || root->val==val ){
            return root;
        }
        else if(root->val > val){
            return exist(root->left,val); // traverse in left
        }
        else{    //(root->val < val){
            return exist(root->right,val); //traverse in right
        }
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return exist(root,val);
    }
};