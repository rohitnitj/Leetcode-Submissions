class Solution {
private:
    bool isPrefixAndSuffix(string &s1, string &s2 ) {
        if( s1.size() > s2.size() ) return false ;
        
        int i = 0 , j = 0 ;
        bool flag = true ;
        while( i < s1.size() && j < s2.size() ) {
            if ( s1[i] != s2[j] ) {
                flag = false ;
                break ;
            }
            i++ , j++ ;
        }
        if( i != j ) flag = false ;
        
        i = s1.size() , j = s2.size() ;
        while( i >= 0 && j >= 0 ) {
            if( s1[i] != s2[j] ) {
                flag = false ;
                break ;
            }
            i--, j-- ;
        }
        if( s1.size() - i != s2.size() - j ) flag = false ;
        return flag ;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size() ;
        int ans = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = i+1 ; j < n ; j++ ) {
                if( isPrefixAndSuffix(words[i], words[j] ) ) {
                    ans++ ;
                }
            }
        }

        return ans ;
    }
};