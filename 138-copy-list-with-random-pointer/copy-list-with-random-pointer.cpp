/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL){  //for inserting between the nodes
            Node* v=new Node(temp->val);
            v->next=temp->next;
            temp->next=v;
            temp=temp->next->next;
        }
        
        //for copy of the random pointer
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL) temp->next->random=temp->random->next;  //temp->next->random this is the copy node which is inserted between the nodes

            temp=temp->next->next;
        }

        //extracting part
        Node* dummy = new Node(0);
        temp=dummy;
        Node* itr=head;
        while(itr!=NULL){
            temp->next=itr->next; //this is for answer part which is extracting the inserted nodes
            itr->next = itr->next->next;//moving the iterator pointer to its next node of original list
            temp=temp->next; //moving the temp to store the next inserted nodes 
            //and dummy->next is the answer
            itr=itr->next;  //moving the iterator pointer to 2 step to maintain the original list
        }
        return dummy->next;
    }
};