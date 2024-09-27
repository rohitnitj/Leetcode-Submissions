class MyCalendarTwo {
public:
    map<int,int> mpp ;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mpp[start]++ ;
        mpp[end]-- ;

        int cnt = 0 ;
        for( auto it : mpp ) {
            cnt += it.second ;

            if( cnt == 3 ) {
                mpp[start]-- ;
                mpp[end]++ ;
                return false ;
            }
        }    

        return true ;
    }
};