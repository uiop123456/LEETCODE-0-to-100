class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        int cnt = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        // Asked to delete the head and return the next index
        if (cnt == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int to_reach = cnt - n;
        temp = head;

        while (to_reach-- > 1) {
            temp = temp->next;
        }

    if (temp != nullptr && temp->next != nullptr) {
        temp->next = temp->next->next;
    }
    return head;
    }   
};
