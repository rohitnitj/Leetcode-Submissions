typedef long long ll;

class Solution {
public:
    vector<unordered_map<ll, ll>> dp;

    ll encode(ll num, ll den) {
        return (num << 32) ^ den;
    }

    ll func(ll num, ll den, int idx, vector<int> &nums, ll k) {
        ll g = __gcd(num, den);
        num /= g;
        den /= g;

        ll key = encode(num, den);

        if (dp[idx].count(key)) return dp[idx][key];

        if (idx == nums.size()) {
            return dp[idx][key] = (den == 1 && num == k);
        }

        ll ans = 0;

        ans += func(num, den, idx + 1, nums, k);
        ans += func(num * nums[idx], den, idx + 1, nums, k);
        ans += func(num, den * nums[idx], idx + 1, nums, k);

        return dp[idx][key] = ans;
    }

    int countSequences(vector<int>& nums, long long k) {
        dp.clear();
        dp.resize(nums.size() + 1);
        return func(1LL, 1LL, 0, nums, k);
    }
};