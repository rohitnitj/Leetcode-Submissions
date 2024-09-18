class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b ) {
            string num1 = to_string(a) ;
            string num2 = to_string(b) ;
            return num1 + num2 > num2 + num1 ;
        });

        if( nums[0] == 0 ) return "0" ;

        string ans = "" ;
        for( auto num : nums ) ans += to_string(num) ;
        
        return ans ;
    }
};