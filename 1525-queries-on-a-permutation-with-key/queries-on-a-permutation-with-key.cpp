class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P(m);
        for (int i = 0; i < m; i++)
            P[i] = i + 1;

        vector<int> ans;
        for (int q : queries) {
            int idx = find(P.begin(), P.end(), q) - P.begin();
            ans.push_back(idx);
            
            P.erase(P.begin() + idx);
            P.insert(P.begin(), q);
        }

        return ans;
    }
};
