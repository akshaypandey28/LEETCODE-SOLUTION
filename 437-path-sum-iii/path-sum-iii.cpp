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
    int count=0;
    void sum(TreeNode* root,int targetSum,long long add){
        if(root==NULL) return ;
        add+=root->val;
        if(add==targetSum) count++;
        sum(root->left,targetSum,add);
        sum(root->right,targetSum,add);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        sum(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};