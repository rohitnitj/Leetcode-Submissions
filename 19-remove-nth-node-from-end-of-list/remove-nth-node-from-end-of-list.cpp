class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head, *slow = head ;
        for( int i = 0 ; i < n  ; i++ ) fast = fast -> next ;

        if( fast == NULL ) {
            ListNode* new_head = head -> next ;
            delete head ;
            return new_head ;
        }

        while( fast -> next ) {
            slow = slow -> next ;
            fast = fast -> next ;
        }

        ListNode* node_to_delete = slow -> next ;
        slow -> next = node_to_delete -> next ;
        node_to_delete -> next = NULL ;
        delete node_to_delete ;

        return head ;
    }
};