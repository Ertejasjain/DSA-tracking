class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to seamlessly handle edge cases like removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move the fast pointer n steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers simultaneously until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow is now right before the node that needs to be deleted
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Delete the node to free memory and avoid leaks
        delete nodeToDelete;
        
        // Store the actual new head, free dummy node memory, and return
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};
