class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size() ;
        vector<int> arr(26,0) ;

        for( int i = 0 ; i < n ; i++ ){
            arr[word[i]-'a']++ ;
        }

        sort( arr.rbegin(), arr.rend() ) ;

        int ans = 0 ;
        for( int i = 0 ; i < 26 ; i++ ) {
            if( arr[i] == 0 ) break ;
            ans += ( i / 8 + 1 ) * arr[i] ;
        }

        return ans ;
    }
};