class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> arr1(26, 0 ), arr2(26, 0 ) ;
        priority_queue<int> pq1, pq2 ;
        set<char> st1, st2 ;

        for( char a : word1 ) arr1[a-'a']++ ;
        for( char a : word2 ) arr2[a-'a']++ ;

        for( char a : word1 ) st1.insert(a ) ;
        for( char a : word2 ) st2.insert(a ) ;

        for( char a : word1 ) if( st2.find(a) == st2.end() ) return false ;
        for( char a : word2 ) if( st1.find(a) == st1.end() ) return false ;

        for( int a : arr1  ) if( a ) pq1.push(a) ;
        for( int a : arr2  ) if( a  ) pq2.push(a) ;

        if( pq1.size() != pq2.size() ) return false;
        while( !pq1.empty() ) {
            int val1 = pq1.top() ; pq1.pop() ;
            int val2 = pq2.top() ; pq2.pop() ;
            if( val1 != val2  ) return false;
        }

        return true ;
    }
};