class Solution {
private:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mpp(82, 0);
        int ans = -1;

        for (auto num : nums) {
            int dsum = digitSum(num);

            if (mpp[dsum] != 0) {
                ans = max(ans, mpp[dsum] + num);
            }

            mpp[dsum] = max(mpp[dsum], num);
        }

        return ans;
    }
};