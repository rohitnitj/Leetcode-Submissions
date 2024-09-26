class MyCalendar {
public:
    vector<pair<int,int>> bookings ;

    MyCalendar() {
    }
    
    bool book(int start, int end) {
        
        for( const auto &b : bookings ) {
            if( max(b.first,start ) < min(b.second, end ) ) return false ;
        }

        bookings.emplace_back(start, end ) ;
        return true ;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */