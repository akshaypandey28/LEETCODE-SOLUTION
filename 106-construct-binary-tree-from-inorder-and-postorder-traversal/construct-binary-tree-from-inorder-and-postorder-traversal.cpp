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
    TreeNode* build(vector<int> &in,int instart,int inend,vector<int> &post,int poststart,int postend,unordered_map<int,int> &m){
        if(instart > inend || poststart > postend) return NULL;
        TreeNode* root=new TreeNode(post[poststart]);
        int root_idx=m[root->val];
        int rightSubTreeSize=inend-root_idx;
        root->right=build(in,root_idx+1,inend,post,poststart+1,poststart+rightSubTreeSize,m);
        root->left=build(in,instart,root_idx-1,post,poststart+rightSubTreeSize+1,postend,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        reverse(post.begin(),post.end());
        unordered_map<int,int> m;
        for(int i=0; i<in.size(); i++){
            m[in[i]]=i;
        }
        return build(in,0,in.size()-1,post,0,post.size()-1,m);
    }
};