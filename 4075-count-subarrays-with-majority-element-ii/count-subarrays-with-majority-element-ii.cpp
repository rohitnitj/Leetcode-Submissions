class Solution {
    vector<int> bit;
    
    void update(int i, int delta) {
        for (; i < bit.size(); i += i & -i) {
            bit[i] += delta;
        }
    }
    
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        bit.assign(2 * n + 2, 0);
        
        int offset = n + 1;
        long long ans = 0;
        int curr = 0;
        
        update(curr + offset, 1);
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                curr += 1;
            } else {
                curr -= 1;
            }
            
            ans += query(curr + offset - 1);
            update(curr + offset, 1);
        }
        
        return ans;
    }
};