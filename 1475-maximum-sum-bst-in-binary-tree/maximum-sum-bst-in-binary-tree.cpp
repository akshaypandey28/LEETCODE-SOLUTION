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
class NodeValue {
public:
    int minNode, maxNode, maxSize, sum;
    
    NodeValue(int minNode, int maxNode, int maxSize, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
        this->sum = sum;
    }
};
class Solution {
public:
    int result=0;
    NodeValue f(TreeNode* root) {
        if (root == NULL) return NodeValue(INT_MAX, INT_MIN, 0, 0);
        
        //values of the left and right subtree of current tree
        auto left = f(root->left);
        auto right = f(root->right);
        
        //if current node is greater than max of left and smaller than min of left then 
        //it is BST
        if (root->val > left.maxNode and root->val < right.minNode) {
            //it is a BST
            int add = root->val + left.sum + right.sum;
            result=max(add,result);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode),
            left.maxSize + right.maxSize + 1, root->val + left.sum + right.sum);
        }
        //after this line not a BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize), max(left.sum,right.sum));
    }
    int maxSumBST(TreeNode* root) {
        
        f(root);
        return result;
    }
};