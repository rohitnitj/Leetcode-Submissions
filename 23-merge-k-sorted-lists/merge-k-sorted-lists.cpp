class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for (ListNode* l : lists) {
            if (l) pq.push(l);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            
            if (tail->next) {
                pq.push(tail->next);
            }
        }
        
        return dummy.next;
    }
};