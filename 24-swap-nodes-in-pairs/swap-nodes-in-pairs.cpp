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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* a=head;
        ListNode* b=head->next;
        while(a->next!=NULL and b!=NULL){
            swap(a->val,b->val);
            if(a->next->next!=NULL and b->next!=NULL){
                a=a->next->next;
                b=b->next->next;
            }
            else break;
        }
        return head;
    }
};