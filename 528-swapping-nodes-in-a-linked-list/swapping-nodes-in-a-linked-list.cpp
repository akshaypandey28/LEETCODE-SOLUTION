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
        if(head==NULL)  return NULL;
        while(temp!=NULL){
           temp=temp->next;
           len++;
       } 
       if(len==2){
        swap(head->val,head->next->val);
        return head;
       }
       int i=0;
       int j=len-1;
       while(i<len){
       if(i==(k-1) && j==(len-k)){
           ListNode* left=getNode(head,i);
           ListNode* right=getNode(head,j);
           int t=left->val;
           left->val=right->val;
           right->val=t;
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