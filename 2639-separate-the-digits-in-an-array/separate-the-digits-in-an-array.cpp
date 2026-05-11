class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans ; 

        for( int num : nums ) {
            vector<int> temp ; 

            while( num ) {
                temp.push_back(num % 10 ) ; 
                num /= 10 ; 
            }
            
            reverse(temp.begin(), temp.end() ) ; 
            for( int t : temp ) ans.push_back(t ) ; 
        }

        return ans ; 
    }
};