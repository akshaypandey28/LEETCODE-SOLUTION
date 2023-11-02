/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exists(TreeNode* root,TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;

        return exists(root->left,target) || exists(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;

        else if( exists(root->left,p)  and exists(root->right,q)  ) return root; //if p is in left and q is in right

        else if( exists(root->left,q)  and exists(root->right,p)  ) return root; //if p is in right and q is in left

        else if( exists(root->left,p)  and exists(root->left,q)  ) return lowestCommonAncestor(root->left, p, q); //if p and q both are in left

        else  return lowestCommonAncestor(root->right, p, q); //if p and q both are in right   //( exists(root->right,p)  and exists(root->right,q)  )



    }
};