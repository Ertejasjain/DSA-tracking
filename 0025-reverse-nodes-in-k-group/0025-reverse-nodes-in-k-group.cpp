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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (true) {
            ListNode* node = prev;
            // Check if there are k nodes to reverse
            for (int i = 0; i < k && node; ++i) {
                node = node->next;
            }
            if (!node) break;

            ListNode* curr = prev->next;
            ListNode* nex = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
        }
        return dummy.next;
    }
};
