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
    void btp(TreeNode* root,vector<string> &ans,string s){
        if(root==NULL) return ;
        string a=to_string(root->val);
        if(root->left==NULL and root->right==NULL) {
            s=s+a;
            ans.push_back(s);
            return ;
        }
        btp(root->left,ans,s+a+"->");
        btp(root->right,ans,s+a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        btp(root,result,"");
        return result;
    }
};