class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size() ;

        int cnt = 0 ; 
        for( int i = 0 ; i < n ; i++ ) {
            if( s1[i] == s2[i] ) continue ; 
            
            if( s1[i] == '0' ) {
                s1[i] = '1' ; 
                cnt++ ; 
            }
            else if( s1[i] == '1' ) {
                if( i+1 < n ) {
                    if( s1[i+1] == '1' ) {
                        s1[i] = '0' ; 
                        s1[i+1] = '0' ;
                        cnt++ ; 
                    }
                    else{
                        s1[i] = '0' ; 
                        cnt += 2 ; 
                    }
                }
                else if( i > 0 ) {
                    if( s1[i-1] == '1' ) {
                        s1[i] = '0' ; 
                        cnt += 2 ; 
                    }
                    else{
                        s1[i] = '0' ; 
                        cnt += 2 ;
                    }
                }
                else return -1 ; 
            }
        }

        return cnt ; 
    }
};