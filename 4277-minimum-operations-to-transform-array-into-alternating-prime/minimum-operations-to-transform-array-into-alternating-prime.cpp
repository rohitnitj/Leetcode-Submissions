class Solution {
public:
    const int N = 2e5 + 7 ; 
    
    int minOperations(vector<int>& nums) {
        int n = nums.size() ; 

        vector<bool> prime(N, true ) ;
        prime[0] = false, prime[1] = false ; 
        
        for( int i = 2 ; i * i <= N ; i++ ) {
            if( prime[i] == true ) {
                for( int j = i * i ; j < N ; j += i ) prime[j] = false ; 
            }
        }

        vector<int> sieve ; 
        for( int i = 2; i < N ; i++ ) {
            if( prime[i] ) sieve.push_back( i ) ; 
        }

        vector<int> next_prime( N + 2 ) ; 
        int last_prime = N + 7 ; 
        for( int i = N-1 ; i >= 0 ; i-- ){
            if( prime[i] ) last_prime = i ; 
            next_prime[i] = last_prime ; 
        }

        int ans = 0 ; 
        
        for( int i = 0 ; i < n; i++  ) {
            if( i & 1 ) {
                if( prime[nums[i]] ) {
                    if( nums[i] == 2 ) ans += 2 ; 
                    else ans++ ; 
                }
            }
            else{
                if( !prime[nums[i]] ) {
                    ans += ( next_prime[nums[i]] - nums[i] ) ; 
                }
            }
        }

        return ans; 
    }
};