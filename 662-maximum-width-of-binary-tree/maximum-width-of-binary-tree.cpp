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
#define pp pair<TreeNode*,int>
#define ll long long
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pp> q;
        q.push({root,0});
        while(q.empty()!=1){
            int size=q.size();
            int curMin = q.front().second;
            int leftMost, rightMost;
            for(int i=0; i<size; i++){
                TreeNode* temp=q.front().first;
                int curr_idx=q.front().second-curMin;
                q.pop();
                
                if(i==0) leftMost=curr_idx;
                if(i==size-1) rightMost=curr_idx;
                if(temp->left!=NULL) q.push({temp->left,(ll)curr_idx*2+1});    
                if(temp->right!=NULL) q.push({temp->right,(ll)curr_idx*2+2});    
            }
            ans=max(ans,rightMost-leftMost+1);
        }
        return ans;

    }
};