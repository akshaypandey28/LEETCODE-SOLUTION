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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        if(k%size==0) return head;
        k=k%size;
        temp=head;
        int a=size-k;
        while(a-- and temp->next!=NULL) temp=temp->next;
        ListNode* curr=temp;
        ListNode* ans=curr;
        while(curr->next!=NULL)  curr=curr->next;
        curr->next=head;
        a=size-k;
        while(a--)  curr=curr->next;
        curr->next=NULL;
        return ans;

    }
};