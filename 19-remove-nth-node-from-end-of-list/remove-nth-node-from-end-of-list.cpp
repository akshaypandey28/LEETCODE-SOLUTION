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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            curr=curr->next;
            count++;
        }
        curr=head;
        if(count==n) return curr->next;
        int c=count-n;
        //int b=0;
        while(curr!=NULL){
            c--;
            if(c==0) break;
            curr=curr->next;
            // b++;
            // if(b>c-1) break;
            // curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};