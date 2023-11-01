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
    bool same(TreeNode* p, TreeNode* q){
        if(p==NULL and q==NULL) return true;
        if(p==NULL and q!=NULL || p!=NULL and q==NULL) return false;
        if(p->val!=q->val) return false;
        return same(p->left,q->left) and same(p->right,q->right);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return same(p,q);
    }
};