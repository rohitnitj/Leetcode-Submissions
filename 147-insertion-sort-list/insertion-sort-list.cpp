class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode* dummy = new ListNode(0) ;
        dummy -> next = head ;
        ListNode* prev = dummy , *curr = head ;

        while( curr ) {
            if( ( curr -> next ) && ( curr -> next -> val < curr -> val ) ) {
                while( ( prev -> next ) && ( prev -> next -> val < curr -> next -> val ) ) 
                    prev = prev -> next ;
                
                ListNode *temp = prev -> next ;
                prev -> next = curr -> next ;
                curr -> next = curr -> next -> next ;
                prev -> next -> next = temp ;
                prev = dummy ;
            }
            else curr = curr -> next ;
        }

        return dummy -> next ;
    }
};