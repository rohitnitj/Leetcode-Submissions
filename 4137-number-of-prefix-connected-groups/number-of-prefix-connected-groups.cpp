class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {

        map<string, int> mpp;

        for (auto word : words) {
            string curr = "";
            int w = word.size();

            for (int i = 0; i < min(k, w); i++)
                curr += word[i];

            mpp[curr]++;
        }

        int ans = 0;
        for (auto &[s, f] : mpp) {
            if (f >= 2 && s.size() == k)
                ans++;
        }

        return ans;
    }
};