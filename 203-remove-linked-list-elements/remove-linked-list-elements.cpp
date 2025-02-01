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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);  // Dummy node
        dummy->next = head;  // Connect dummy to head
        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->val == val) {
                prev->next = temp->next;  // Skip current node
            } else {
                prev = temp;  // Move prev only if not deleting
            }
            temp = temp->next;  // Always move temp
        }

        return dummy->next;  // Return new head
    }
};
