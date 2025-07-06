class FindSumPairs {
private:
    vector<int> arr1, arr2 ;
    unordered_map<int,int> mpp ;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1 ;
        arr2 = nums2 ;
        for( int a : arr2 ) mpp[a]++ ;
    }

    void add(int index, int val) {
        mpp[arr2[index]]-- ;
        arr2[index] += val ;
        mpp[arr2[index]]++ ;
    }

    int count(int tot) {
        int cnt = 0 ;
        for( int a : arr1 ) {
            int r = tot - a ;
            if( mpp.count(r ) ) cnt += mpp[r] ;
        }
        return cnt ;
    }
};