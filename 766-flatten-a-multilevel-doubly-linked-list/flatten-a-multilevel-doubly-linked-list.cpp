/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    vector<int> values;
    void f(Node* head){
        if(head==NULL) return ;

        values.push_back(head->val);
        if(head->child!=NULL) f(head->child);

        f(head->next);
    }
    Node* flatten(Node* head) {
        f(head);
        Node* dummy=new Node(0);
        Node* temp=dummy;
        for(int ele:values) {
            Node* new_node=new Node(ele);
            temp->next=new_node;
            new_node->prev=temp;
            temp=temp->next;
        }
        
        Node* result = dummy->next;
        if (result) result->prev = NULL;
        delete dummy; // Avoid memory leak
        
        return result;
    }
};