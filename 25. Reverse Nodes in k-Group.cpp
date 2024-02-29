
class Solution {
public:
    ListNode *reverse(ListNode *head,ListNode *null){
        ListNode *curr, *prev=null;
        while(head!=null){
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode *node = head;
       // Check if there are at least 'k' nodes remaining and traversing to the end of the LL
       for(int i=0;i<k;i++){
           if(!node) return head;
           node = node->next;
        }
        auto new_head = reverse(head,node);
        head->next=reverseKGroup(node,k);
        return new_head;
    }
};
