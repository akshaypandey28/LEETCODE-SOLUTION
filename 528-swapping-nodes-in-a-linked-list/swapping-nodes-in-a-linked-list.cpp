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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=1;
        ListNode* temp=head;
        while(count<k && temp!=NULL){
            temp=temp->next;
            count++;
        }
        int val1=temp->val;
        temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        count=1;
        temp=head;
        while(count<=(len-k) && temp!=NULL){
            temp=temp->next;
            count++;
        }
        int val2=temp->val;
        temp->val=val1;
        temp=head;
        count=1;
        while(count<k && temp!=NULL){
            temp=temp->next;
            count++;
        }
        temp->val=val2;
        return head;
    }
};