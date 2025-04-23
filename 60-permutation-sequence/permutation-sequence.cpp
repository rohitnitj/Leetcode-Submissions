class Solution {
private:
    void nextPermutation(string& nums) {
        int n = nums.size() ;
        int ind = -1 ;
        for(int i = n-2 ; i >= 0 ; i-- ) {
            if( nums[i] < nums[i+1] ) {
                ind = i ;
                break ;
            }
        }

        if( ind == -1 ){
            reverse(nums.begin(), nums.end() ) ;
            return ;
        }

        for( int i = n-1 ; i > ind ; i-- ) {
            if( nums[i] > nums[ind] ) {
                swap(nums[i], nums[ind] ) ;
                break ;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end() ) ;
    }    

public:
    string getPermutation(int n, int k) {
        string s = "";
        for( int i = 1; i <= n ; i++ ) s += to_string(i) ;

        for(int i = 1; i < k; i++) nextPermutation(s);
        return s;
    }
};