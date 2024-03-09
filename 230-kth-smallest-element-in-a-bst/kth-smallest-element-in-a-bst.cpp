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
    int ans=0;
    bool f(TreeNode* root, int k, int& count) {
        if (root == nullptr) 
            return false;
        
        if (f(root->left, k, count)) 
            return true;
        
        count++;
        if (count == k) {
            ans = root->val;
            return true;
        }
        
        return f(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        bool a=f(root,k,count);
        return ans;
    }
};