class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head ;
        int n = 0 ; 
        while( temp != NULL ) {
            temp = temp -> next ; 
            n++ ;
        }

        int first = 1 ;
        int second = 1 ;
        ListNode* swap1 = head ;
        ListNode* swap2 = head ;

        while( first != k ) {
            swap1 = swap1 -> next ;
            first++ ;
        }

        while( second != n-k+1 ) {
            swap2 = swap2 -> next ;
            second++ ;
        }

        int temporary = swap1 -> val ;
        swap1 -> val = swap2 -> val ;
        swap2 -> val = temporary ;

        return head ;        
    }
};