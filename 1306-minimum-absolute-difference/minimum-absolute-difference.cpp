class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        
        int best = INT_MAX;
        for(int i = 1; i < n; i++) {
            best = min(best, arr[i] - arr[i-1]);
        }

        vector<vector<int>> ans;
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i-1] == best) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }

        return ans;
    }
};