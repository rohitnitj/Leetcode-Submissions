class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0 ;
        ListNode* temp = head ;

        while (temp ) {
            sz++ ;
            temp = temp -> next ;
        }      

        if ( n == sz ) {
            ListNode *node_to_delete = head ;
            head = head -> next ;
            delete node_to_delete ;
            return head ;
        }

        temp = head ;
        int cnt = sz - n ;

        while( cnt > 1  ) {
            temp = temp -> next ;
            cnt-- ;
        }

        ListNode *node_to_delete = temp -> next ;
        temp -> next = node_to_delete -> next ;
        delete node_to_delete ;

        return head ;
    }
};
