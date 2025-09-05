class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long remain = (long long)num1 - (long long)k * num2;
            if (remain < 0) continue; // cannot be negative
            int bits = __builtin_popcountll(remain);
            if (bits <= k && remain >= k) {
                return k;
            }
        }
        return -1;
    }
};
