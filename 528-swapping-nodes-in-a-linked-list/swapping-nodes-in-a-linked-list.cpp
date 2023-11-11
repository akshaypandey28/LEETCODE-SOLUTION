class Solution {
public:
    ListNode* getNode(ListNode* head,int idx){
        ListNode* temp=head;
        for(int i=1;i<=idx;i++){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* swapNodes(ListNode* head, int k) {
       int len=0;
       ListNode* temp=head;
        while(temp!=NULL){
           temp=temp->next;
           len++;
       } 
       int i=0;
       int j=len-1;
       while(i<len){
       if(i==(k-1) && j==(len-k)){
           ListNode* left=getNode(head,i);
           ListNode* right=getNode(head,j);
           swap(right->val,left->val);
           return head;
       }
       else{
            i++;
            j--;
       }
       }
      return head;
    }
};