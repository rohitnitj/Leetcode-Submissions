class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
            if (x[1] == y[1]) return x[0] > y[0];
            return x[1] < y[1];
        });

        int count = 0;
        int a = -1, b = -1;

        for (auto& in : intervals) {
            int l = in[0], r = in[1];

            bool hasA = (a >= l);
            bool hasB = (b >= l);

            // Already two elements inside
            if (hasA && hasB) continue;

            // Only one element inside
            if (hasB) {
                // Add r
                count++;
                a = b;
                b = r;
            } 
            // No element inside
            else {
                // Add r-1 and r
                count += 2;
                a = r - 1;
                b = r;
            }
        }

        return count;
    }
};
