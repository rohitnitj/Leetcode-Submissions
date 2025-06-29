class Solution {
public:
   bool findSuccessors(vector<int>& hand, int gs, int i, int n) {
        int next = hand[i] + 1;
        hand[i] = -1;  
        int cnt = 1;
        i++ ;

        while( i < n && cnt < gs ) {
            if( hand[i] == next ) {
                next = hand[i] + 1 ;
                hand[i] = -1 ;
                cnt++ ;
            }
            i++ ;
        }

        return cnt == gs ;
    }

    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size() ;
        if( n % gs != 0 ) return false ;
        sort(hand.begin(), hand.end() ) ;

        for( int i = 0 ; i < n ; i++ ) {
            if( hand[i] >= 0 ) {
                if( !findSuccessors(hand, gs, i, n ) ) return false ;
            }
        }

        return true ;
    }
};