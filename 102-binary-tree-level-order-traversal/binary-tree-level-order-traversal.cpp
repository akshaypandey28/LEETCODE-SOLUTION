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
    int findLevel(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(findLevel(root->left) ,findLevel(root->right));
    }
    void pre(TreeNode* root,int currLevel,int reqLevel,vector<int> &temp){
        if(root==NULL) return ;
        if(currLevel==reqLevel) temp.push_back(root->val);
        pre(root->left,currLevel+1,reqLevel,temp);
        pre(root->right,currLevel+1,reqLevel,temp);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        vector<int> temp;
        int n=findLevel(root);
        for(int i=1; i<=n; i++){
            pre(root,1,i,temp);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};