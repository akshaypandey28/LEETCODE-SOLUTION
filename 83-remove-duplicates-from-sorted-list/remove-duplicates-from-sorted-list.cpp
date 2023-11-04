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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp=head->next;
        ListNode* head1=head;
        ListNode* ans=head1;
        unordered_set<int> s;
        s.insert(head->val);
        while(temp!=NULL){
            if(s.count(temp->val)==1){
                temp=temp->next;
            }
            else{
                s.insert(temp->val);
                head1->next=temp;
                head1=head1->next;
                temp=temp->next;
            }
        }
        head1->next=NULL;
        return ans;
    }
};