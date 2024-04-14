/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()!=1){
            TreeNode* top=q.front();
            q.pop();
            if(top!=NULL){
                s+=to_string(top->val)+",";
                q.push(top->left);
                q.push(top->right);
            }
            else s += "#,";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()!=1){
            TreeNode* top = q.front();
            q.pop();
            getline(s,str,','); //for the left part
            if(str!="#"){
                TreeNode* l=new TreeNode(stoi(str)); //left node
                top->left=l;
                q.push(l);
            }
            getline(s,str,','); //for the right part
            if(str!="#"){
                TreeNode* r=new TreeNode(stoi(str)); //right node
                top->right=r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));