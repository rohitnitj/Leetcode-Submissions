class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> arr1(26, 0 ), arr2(26, 0 ) ;

        for( char a : word1 ) arr1[a-'a']++ ;
        for( char a : word2 ) arr2[a-'a']++ ;

        for( int i = 0 ; i < 26 ; i++ ) if( ( arr1[i] == 0 ) != ( arr2[i] == 0 ) ) return false ;
        
        sort(arr1.begin(), arr1.end() ) ;
        sort(arr2.begin(), arr2.end() ) ;

        return arr1 == arr2 ;
    }
};