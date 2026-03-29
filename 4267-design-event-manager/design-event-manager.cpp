class EventManager {
public:
    set<pair<int, int>> st ; 
    map<int, int> mpp ; 
    
    EventManager(vector<vector<int>>& events) {
        for( auto &it : events ){
            int id = it[0], pr = it[1] ; 
            st.insert( {-pr, id } ) ;
            mpp[id] = pr ; 
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int op = mpp[eventId] ; 
        st.erase( {-op, eventId } ) ; 
        st.insert( { -newPriority, eventId } ) ;
        mpp[eventId] = newPriority ; 
    }
    
    int pollHighest() {
        if( st.empty() ) return -1 ; 
        auto it = st.begin() ; 
        int id = it -> second ; 
        st.erase(it) ; 
        mpp.erase(id) ; 
        return id ; 
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */