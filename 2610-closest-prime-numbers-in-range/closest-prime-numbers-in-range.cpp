class Solution {
private:
    vector<int> seive(int n ) {
        vector<int> seive(n+1, 1 ) ;
        seive[0] = seive[1] = 0 ;

        for( int i = 2 ; i*i <= n ; i++ ) {
            if( seive[i] == 1 ) {

                for( int j = i*i ; j <= n ; j += i ) {
                    seive[j] = 0 ;
                }
            }
        }

        return seive ;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> seive_arr = seive(right ) ;
        vector<int> arr ;
        for (int i = left ; i <= right; i++ ) {
            if( seive_arr[i] ) arr.push_back(i) ;
        }

        if( arr.size() <= 1 ) return {-1, -1} ;
        if( arr.size() == 2 ) return arr ;
        
        int mini = 1e9 ;
        vector<int> ans ;
        for(int i = 0; i < arr.size() - 1 ; i++ ) {
            if( abs(arr[i+1] - arr[i] ) < mini ) {
                ans = {arr[i], arr[i+1] } ;
                mini = abs( arr[i+1] -arr[i] ) ;
            }
        }

        return ans ;
    }
};