class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* midHead = head;

        int totalNode = 0;
        
        while(head != NULL){
            totalNode++;
            head = head->next;
        }

        int midNode = (totalNode / 2) + 1;

        int count = 1;

        while(count < midNode){
            midHead = midHead->next;
            count++;
        }

        return midHead;
    }
};