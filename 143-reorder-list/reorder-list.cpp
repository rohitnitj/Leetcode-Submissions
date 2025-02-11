class Solution {
public:
    void reorderList(ListNode* head) {
        deque<int> dq ;
        ListNode *curr = head ;

        while( curr ) {
            dq.push_back(curr -> val ) ;
            curr = curr -> next ;
        }

        curr = head ;
        dq.pop_front() ;
        curr = curr -> next ;

        while( !dq.empty()) {

            curr -> val = dq.back() ;
            curr = curr -> next ;
            dq.pop_back() ;

            if( !dq.empty() ) {
                curr -> val = dq.front() ;
                curr = curr -> next ;
                dq.pop_front() ;
            }
        }
    }
};