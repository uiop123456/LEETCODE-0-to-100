/**
        1. find middle
        2. reverse middle
        3. comparision
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head, *prev, *temp;
        while(fast && fast->next)
            slow=slow->next,fast=fast->next->next;
        prev=slow; // prev point to the middle of the LL

        slow = slow->next;//start of 2nd LL
        prev->next=NULL;    //disconnet the 1st and 2nd LL

        while(slow){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

        //reset pointer
        fast=head;
        slow=prev;
        while(slow){
            if(fast->val!=slow->val) return false;
            else{
                slow=slow->next;
                fast=fast->next;
            }
        }
        return true;

    }
};
