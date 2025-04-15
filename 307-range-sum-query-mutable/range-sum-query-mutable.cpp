class NumArray {
private:
    vector<int> segmentTree;
    int n;

    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }

    int buildTree(vector<int>& nums, int ss, int se, int si) {
        if (ss == se) {
            segmentTree[si] = nums[ss];
            return nums[ss];
        }

        int mid = getMid(ss, se);
        segmentTree[si] = buildTree(nums, ss, mid, si * 2 + 1) +
                          buildTree(nums, mid + 1, se, si * 2 + 2);
        return segmentTree[si];
    }

    void updateUtil(int ss, int se, int index, int diff, int si) {
        if (index < ss || index > se) return;

        segmentTree[si] += diff;
        if (ss != se) {
            int mid = getMid(ss, se);
            updateUtil(ss, mid, index, diff, 2 * si + 1);
            updateUtil(mid + 1, se, index, diff, 2 * si + 2);
        }
    }

    int getSumUtil(int ss, int se, int qs, int qe, int si) {
        if (qs <= ss && qe >= se) return segmentTree[si];
        if (se < qs || ss > qe) return 0;

        int mid = getMid(ss, se);
        return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
               getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
    }

    vector<int> originalArr;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        originalArr = nums;
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        segmentTree.resize(max_size, 0);
        buildTree(nums, 0, n - 1, 0);
    }

    void update(int index, int val) {
        if (index < 0 || index >= n) return;
        int diff = val - originalArr[index];
        originalArr[index] = val;
        updateUtil(0, n - 1, index, diff, 0);
    }

    int sumRange(int left, int right) {
        if (left < 0 || right >= n || left > right) return 0;
        return getSumUtil(0, n - 1, left, right, 0);
    }
};