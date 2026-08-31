class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == NULL) {
                    return dummy->next;
                }
            }

            // Save the next group
            ListNode* groupNext = kth->next;

            // Reverse the current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous part to reversed group
            ListNode* oldGroupStart = groupPrev->next;

            groupPrev->next = kth;

            // Old start becomes the tail
            groupPrev = oldGroupStart;
        }
    }
};