class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        map<string, int> mpp;

        for (int i = 0; i <= n - minSize; i++) {
            string temp = s.substr(i, minSize);

            set<char> st(temp.begin(), temp.end());
            if (st.size() <= maxLetters) {
                mpp[temp]++;
            }
        }

        int ans = 0;
        for (auto &it : mpp) {
            ans = max(ans, it.second);
        }

        return ans;
    }
};
