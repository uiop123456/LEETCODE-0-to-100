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
    ListNode* findNthNode(ListNode* head, int k){
        int count = 1;
        while(head!=NULL && count < k){  // Add "count < k" condition
            count++;
            head=head->next;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        int length=1;
        ListNode *tail=head;

        while(tail->next!=NULL){
            length++;
            tail=tail->next;
        }

        k=k%length;
        if(k==0) return head;  // No rotation needed

        // Attach the tail to the head
        tail->next=head;

        ListNode *newLastNode=findNthNode(head, length - k);

        head=newLastNode->next;
        newLastNode->next=NULL;
        return head;
    }
};
