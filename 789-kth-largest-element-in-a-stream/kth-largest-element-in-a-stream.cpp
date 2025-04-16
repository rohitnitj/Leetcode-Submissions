class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq ;
    int k ;

public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k ;

        for( int num : nums )
            add(num ) ;
    }
    
    int add(int val) {
        
        if( pq.size() < k || pq.top() < val )  {
            pq.push( val ) ;

            if( pq.size() > k ) {
                pq.pop() ;
            }
        }

        return pq.top() ;
    }
};