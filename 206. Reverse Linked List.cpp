
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* curr=head,*prev =NULL;
        while(head!=NULL){
            curr=head->next;
            head->next=prev;
            prev=head;
            head=curr;
        }
        return prev;
    }
};
