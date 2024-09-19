class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        deque<int> dq ;

        while( temp != NULL ) {
            dq.push_back(temp -> val ) ;
            temp = temp -> next ;
        }

        temp = head ;
        dq.pop_front() ;
        temp = temp -> next ;

        while( !dq.empty() ) {
            temp -> val = dq.back() ;
            dq.pop_back() ;
            temp = temp -> next ;

            if( !dq.empty() ) {
                temp -> val = dq.front() ;
                dq.pop_front()  ;
                temp = temp -> next ;
            }    
        }
    }
};
