class Solution {
private:    
    void countSort(vector<int> &arr, int n, int p) {
        vector<int> ans(n), cnt(10, 0);

        for (int i = 0; i < n; i++) {
            cnt[(arr[i] / p) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            ans[cnt[(arr[i] / p) % 10] - 1] = arr[i];
            cnt[(arr[i] / p) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
    }

    void radixSort(vector<int>& arr) {
        if (arr.empty()) return;
        int maxi = *max_element(arr.begin(), arr.end());

        for (int p = 1; maxi / p > 0; p *= 10) {
            countSort(arr, arr.size(), p);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> positive, negative;
        
        for (int num : nums) {
            if (num < 0) {
                negative.push_back(-num);
            } else {
                positive.push_back(num);
            }
        }

        radixSort(positive);
        radixSort(negative);

        vector<int> sortedArray;
        
        for (int i = negative.size() - 1; i >= 0; i--) {
            sortedArray.push_back(-negative[i]);
        }

        sortedArray.insert(sortedArray.end(), positive.begin(), positive.end());

        return sortedArray;
    }
};