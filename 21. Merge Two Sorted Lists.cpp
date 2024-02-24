class Solution {
public:
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();  
    ListNode* ans = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            ans->next = list1;
            list1 = list1->next;
        } else {
            ans->next = list2;
            list2 = list2->next;
        }
        ans = ans->next;
    }

    if (list1 != nullptr) {
        ans->next = list1;
    } else {
        ans->next = list2;
    }

    return dummy->next;
}

};
