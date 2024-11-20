/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool f(ListNode* head,TreeNode* root){
        if(head == NULL) return true; //root can be null or can't be null
        if(root==NULL) return false;
        
        if(head->val == root->val){
            return (f(head->next , root->left) || f(head->next , root->right));
        }
        
        return false; //dummy line 
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) return false;
        if(head->val==root->val){
            if(f(head,root)) return true;
        }
        //mutlisource dfs
        return isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};