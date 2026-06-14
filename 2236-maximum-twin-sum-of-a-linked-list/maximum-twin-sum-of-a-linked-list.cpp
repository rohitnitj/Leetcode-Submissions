/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        int maxi = 0 ;

        while( fast && fast -> next ) {
            fast = fast -> next -> next ;
            slow = slow -> next ;
        }

        ListNode* next_node , *prev = NULL ;
        while( slow ) {
            next_node = slow -> next ;
            slow -> next = prev ;
            prev = slow ;
            slow = next_node ;
        }

        while(prev ) {
            maxi = max(maxi, head -> val + prev -> val ) ;
            prev = prev -> next ;
            head = head -> next ;
        }

        return maxi ;
    }
};