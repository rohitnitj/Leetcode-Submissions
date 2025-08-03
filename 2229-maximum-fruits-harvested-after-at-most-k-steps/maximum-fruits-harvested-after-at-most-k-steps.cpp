class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), amt(n);
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            amt[i] = fruits[i][1];
        }

        // prefix sum of amounts
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + amt[i];

        int res = 0;

        // left then right
        for (int d = 0; d <= k; ++d) {
            int left = startPos - d;
            int right = startPos + (k - 2 * d);
            if (left > right) continue;
            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, (int)(prefix[r] - prefix[l]));
        }

        // right then left
        for (int d = 0; d <= k; ++d) {
            int right = startPos + d;
            int left = startPos - (k - 2 * d);
            if (left > right) continue;
            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, (int)(prefix[r] - prefix[l]));
        }

        return res;
    }
};
