class Solution {
private:
    bool check_prime(int n ) {
        if( n < 2 ) return false ;
        for( int i = 2 ; i*i <= n ; i++ ) {
            if( n % i == 0 ) return false ;
        }
        return true ;
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1 ) return true ;

        for( int i = n-2 ; i >= 0 ; i-- ) {

            if( nums[i] >= nums[i+1] ) {
                int diff = nums[i] - nums[i+1] ;
                int min_prime = -1 ;
                
                for( int j = diff+1 ; j < nums[i] ; j++ ) {
                    if( check_prime(j ) ){
                        min_prime = j ;
                        break ;
                    }
                }

                if( min_prime == -1 ) return false ;
                else nums[i] = nums[i] - min_prime ;
            }
        }

        return true ;
    }
};