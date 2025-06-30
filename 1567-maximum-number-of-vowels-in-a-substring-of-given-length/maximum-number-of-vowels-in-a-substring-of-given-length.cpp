class Solution {
public:
    int func(vector<int>& arr) {
        return arr['a' - 'a'] + arr['e' - 'a'] + arr['i' - 'a'] + arr['o' - 'a'] + arr['u' - 'a'];
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> arr(26, 0);

        int j = 0, ans = 0;
        for (j = 0; j < min(k, n); j++) arr[s[j] - 'a']++;
        ans = func(arr);

        for (j = k; j < n; j++) {
            arr[s[j] - 'a']++;
            arr[s[j - k] - 'a']--;
            ans = max(ans, func(arr));
        }

        return ans;
    }
};
