class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL ) 
            return head;

        ListNode* newHead = head -> next ;
        ListNode* prev = NULL ;
        ListNode* curr = head ; 

        while( curr && curr -> next ){
            ListNode* next = curr -> next ;

            curr -> next = next -> next ;
            next -> next = curr ;

            if( prev != NULL ) prev -> next = next ;

            prev = curr ;
            curr = curr -> next ;
        }

        return newHead ;
    }
};