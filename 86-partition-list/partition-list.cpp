class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0); // Dummy head for < x
        ListNode* afterHead = new ListNode(0);  // Dummy head for >= x
        ListNode* before = beforeHead;
        ListNode* after = afterHead;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } 
            else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr;       // End the 'after' list
        before->next = afterHead->next; // Connect before list to after list

        return beforeHead->next;
    }
};