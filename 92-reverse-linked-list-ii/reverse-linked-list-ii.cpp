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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // node before the left position
        ListNode* leftConnector = dummy;
        for(int i = 1; i < left; i++)  leftConnector = leftConnector->next;
        
        // Reverse the sublist
        ListNode* prev = NULL;
        ListNode* curr = leftConnector->next;
        for(int i = left; i <= right; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Reconnect the reversed sublist with the rest of the list
        leftConnector->next->next = curr; // Connect the tail of the reversed sublist to the rest
        leftConnector->next = prev;      // Connect the head of the reversed sublist to leftConnector

        return dummy->next; // Return the new head of the list
    }
};



/* 
//Approach-3 (Using Stack for One Pass Flow)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head || !head->next)
            return head;
        
        stack<ListNode*> st;
        ListNode* dummy = new ListNode(0); //to which prev points in the beginning (Example : 1 -> 2)
        dummy->next = head;
        ListNode* prev = dummy;
        
        for(int i = 1; i<=left-1; i++) {
            prev = prev->next;
        }
        
        //put [left, right] elements on stack
        ListNode* curr = prev->next;
        for(int i = left; i<= right; i++) {
            st.push(curr);
            curr = curr->next;
        }
        
        ListNode* storeRightNext = st.top()->next;
        
        //Now, link them
        while(!st.empty()) {
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }
        
        prev->next = storeRightNext;
        return dummy->next;
    }
};
 */
