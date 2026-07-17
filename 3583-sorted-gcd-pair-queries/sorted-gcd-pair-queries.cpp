class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }

        vector<int> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        vector<long long> G(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long count = 0;
            for (int j = i; j <= max_val; j += i) {
                count += freq[j];
            }
            G[i] = count * (count - 1) / 2;
            for (int j = 2 * i; j <= max_val; j += i) {
                G[i] -= G[j];
            }
        }

        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            pref[i] = pref[i - 1] + G[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            int l = 1, r = max_val;
            int res = max_val;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (pref[mid] > q) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};