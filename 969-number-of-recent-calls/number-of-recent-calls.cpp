class RecentCounter {
private:
    queue<int> q ;
    int cnt ;

public:
    RecentCounter() {
        cnt = 0 ;
    }
    
    int ping(int t) {
        cnt++ ;
        while ( !q.empty() && t - q.front() > 3000 ) {
            q.pop() ;
            cnt-- ;
        }
        q.push(t ) ;
        return cnt ;
    }
};