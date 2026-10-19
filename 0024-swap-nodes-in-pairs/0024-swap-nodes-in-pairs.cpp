class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: No nodes or just one node remaining
        if (!head || !head->next) {
            return head;
        }
        
        // Pointers for the current pair
        ListNode* first = head;
        ListNode* second = head->next;
        
        // Recursively process the rest of the list and link to the current pair
        first->next = swapPairs(second->next);
        second->next = first;
        
        // 'second' is now the new head of this local pair
        return second;
    }
};
