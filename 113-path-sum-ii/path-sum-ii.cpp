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
    void sum(TreeNode* root, int targetSum,int add,vector<vector<int>> &ans,vector<int> temp){
        if(root==NULL) return ;
        add=add+root->val;
        temp.push_back(root->val);
        if(add==targetSum && root->left==NULL && root->right==NULL) ans.push_back(temp);
        
        sum(root->left,targetSum,add,ans,temp); 
        sum(root->right,targetSum,add,ans,temp); 

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        sum(root,targetSum,0,ans,temp);
        return ans;
    }
};