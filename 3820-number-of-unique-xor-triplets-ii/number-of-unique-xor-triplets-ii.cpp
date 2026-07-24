#include <vector>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        bool U_mark[2048] = {false};
        std::vector<int> U;
        for (int x : nums) {
            if (!U_mark[x]) {
                U_mark[x] = true;
                U.push_back(x);
            }
        }
        
        bool S2[2048] = {false};
        int n = U.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                S2[U[i] ^ U[j]] = true;
            }
        }
        
        bool S3[2048] = {false};
        int uniqueTripletsCount = 0;
        
        for (int x = 0; x < 2048; ++x) {
            if (S2[x]) {
                for (int y : U) {
                    if (!S3[x ^ y]) {
                        S3[x ^ y] = true;
                        uniqueTripletsCount++;
                    }
                }
            }
        }
        
        return uniqueTripletsCount;
    }
};