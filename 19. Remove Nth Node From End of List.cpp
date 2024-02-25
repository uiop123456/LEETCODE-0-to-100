//2n
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

// n
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0 || head == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) return head; 
            fast = fast->next;
        }

        // Handle the case when removing the head
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the N-th node from the end
        if (slow->next != nullptr) {
            ListNode* toRemove = slow->next;
            slow->next = slow->next->next;
            delete toRemove;
        }

        return head;
    }
};

