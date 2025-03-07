class Solution {
private:
    bool isPrime(int n ) {
        if( n == 1 ) return false ;
        bool f = true ;
        for( int i = 2; i*i <= n ; i++ ) {
            if( n % i == 0 ) {
                f = false ;
                break ;
            }
        }
        return f ;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> arr ;
        for (int i = left ; i <= right; i++ ) {
            if( isPrime(i ) ) arr.push_back(i) ;
        }

        if( arr.size() <= 1 ) return {-1, -1} ;
        if( arr.size() == 2 ) return arr ;
        
        int mini = 1e9 ;
        vector<int> ans ;
        for(int i = 0; i < arr.size() - 1 ; i++ ) {
            if( abs(arr[i+1] - arr[i] ) < mini ) {
                // cout << arr[i] << " " << arr[i+1] << endl ;
                ans = {arr[i], arr[i+1] } ;
                mini = abs( arr[i+1] -arr[i] ) ;
            }
        }

        return ans ;
    }
};