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
    void solve(TreeNode* root,int value,int &count){
        if(root==NULL) return ;
        if(root->val>=value){
            count++;
            value=root->val;
        }
        solve(root->left,value,count);
        solve(root->right,value,count);

    }
    int goodNodes(TreeNode* root) {
        int count=1;//because of root
        solve(root->left,root->val,count);
        solve(root->right,root->val,count);
        return count;
    }
};