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
    void sum(TreeNode* root, int targetSum,long long add,int &count){
        if(root==NULL) return ;
        add=add+root->val;
        if(add==targetSum) count++;
        sum(root->left,targetSum,add,count); 
        sum(root->right,targetSum,add,count); 
    }
    int pathSum(TreeNode* root, int targetSum) { //to add the sums of every nodepath
        if(root==NULL) return 0;
        int count=0;
        sum(root,targetSum,0,count);
        count+=pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
        return count;
    }
};