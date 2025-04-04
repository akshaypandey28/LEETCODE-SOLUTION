/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        //connects the left subtree of same level with right subtree of that same level 
        if(root->left) root->left->next=root->right;

        if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        return root;
    }
};


/* 
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(q.empty()!=1){
            int size=q.size();
            while(size--){
                Node* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(size>0) curr->next=q.front();
                
            }
        }
        return root;
    }
};
 */