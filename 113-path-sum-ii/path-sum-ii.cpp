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
    void path(TreeNode* root,int targetSum,vector<vector<int>> &answer,vector<int> v,int sum){
        if(root==NULL) return ;
        sum+=root->val;
        if(root->left==NULL and root->right==NULL and sum==targetSum){
            v.push_back(root->val);
            answer.push_back(v);
            return ;
        }
        v.push_back(root->val);
        path(root->left,targetSum,answer,v,sum);
        path(root->right,targetSum,answer,v,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> v;
        int sum=0;
        path(root,targetSum,answer,v,sum);
        return answer;
    }
};