class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mpp;
        for (string s : words) mpp[s]++;
        
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) return a.second > b.second;  // min-heap for lexicographically smaller
            return a.first < b.first;        // max-heap for frequency
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        
        for (auto& it : mpp) {
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
