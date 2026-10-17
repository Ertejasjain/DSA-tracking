/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the head anchor
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Loop while both lists have remaining elements
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // Move the tail pointer forward
        }
        
        // Append the remaining nodes of the non-empty list
        tail->next = list1 ? list1 : list2;
        
        // The merged list starts right after the dummy node
        return dummy.next;
    }
};
