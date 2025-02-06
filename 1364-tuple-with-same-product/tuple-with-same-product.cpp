class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> prod;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = nums[i] * nums[j];
                prod[p]++;
            }
        }

        for (auto &it : prod) {
            int c = it.second;
            if (c >= 2) cnt += 4 * c * (c - 1); 
        }

        return cnt;
    }
};
