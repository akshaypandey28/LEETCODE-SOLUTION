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
class BSTIterator {
public:
    deque<int> dq;
    void in(TreeNode* root){
        if(root==NULL) return ;
        in(root->left);
        dq.push_back(root->val);
        in(root->right);
    }
    BSTIterator(TreeNode* root) {
        in(root);
    }
    
    int next() {
        int from_front=dq.front();
        dq.pop_front();
        return from_front;
    }
    
    bool hasNext() {
       return dq.size()>=1 ? true:false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */