class Solution {
public:
    int countMonobit(int n) {
        if (n == 0) return 1;
        return 1 + (int)floor(log2(n + 1));
    }
};
