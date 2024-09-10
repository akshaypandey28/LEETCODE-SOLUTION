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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* temp=head;
        vector<int> v;
        while(temp->next!=NULL){
            int maxi=max(temp->val,temp->next->val);
            int mini=min(temp->val,temp->next->val);
            int val=gcd(maxi ,mini);
            v.push_back(val);
            temp=temp->next;
        }
        for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        temp=head;
        int i=0;
        while(temp->next!=NULL){
            ListNode* a=new ListNode(v[i]);
            a->next=temp->next;
            temp->next=a;
            temp=temp->next->next;
            i++;
        }
        return head;
    }
};