class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int cnt = 0, maxi = 0;
        for (auto &interval : intervals) {
            if (interval[1] > maxi) {
                cnt++;
                maxi = interval[1];
            }
        }

        return cnt;
    }
};