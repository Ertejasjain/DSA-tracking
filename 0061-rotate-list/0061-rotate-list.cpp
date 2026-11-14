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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. Handle edge cases: empty list, single node, or zero rotations
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 2. Find the length of the list and reach the current tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // 3. Optimize k to avoid redundant full rotations
        k = k % length;
        if (k == 0) {
            return head;
        }

        // 4. Form a circular linked list
        tail->next = head;

        // 5. Traverse to the new tail: (length - k) steps from the current tail
        int stepsToNewTail = length - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // 6. Set the new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
