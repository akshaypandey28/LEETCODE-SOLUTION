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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2,s3;
        ListNode* a=l1;
        ListNode* b=l2;
        while(a!=NULL){
            s1.push(a->val);
            a=a->next;
        }
        while(b!=NULL){
            s2.push(b->val);
            b=b->next;
        }
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        int rem=0;
        while(s1.empty()!=1 and s2.empty()!=1){
            rem+=s1.top()+s2.top();
            s3.push(rem%10);
            s1.pop();
            s2.pop();
            rem=rem/10;
        }
        while(s1.empty()!=1){
            rem+=s1.top();
            s3.push(rem%10);
            s1.pop();
            rem=rem/10;
        }
        while(s2.empty()!=1){
            rem+=s2.top();
            s3.push(rem%10);
            s2.pop();
            rem=rem/10;
        }
        if(rem!=0) s3.push(rem);
        while(s3.empty()!=1){
            ListNode* value=new ListNode(s3.top());
            s3.pop();
            temp->next=value;
            temp=temp->next;
        }

        return ans->next;
    }
};