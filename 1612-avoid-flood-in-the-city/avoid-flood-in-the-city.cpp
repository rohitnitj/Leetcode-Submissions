#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // default dry any lake as 1
        unordered_map<int, int> full; // lake -> last day it rained
        set<int> dryDays; // indices of days we can dry lakes

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1; // it rained today
                if (full.count(lake)) {
                    auto it = dryDays.upper_bound(full[lake]);
                    if (it == dryDays.end()) return {}; // no available dry day → flood
                    ans[*it] = lake; // dry this lake on that day
                    dryDays.erase(it);
                }
                full[lake] = i;
            } else {
                dryDays.insert(i); // a dry day available
            }
        }

        return ans;
    }
};
