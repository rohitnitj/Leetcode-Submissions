class Solution {
public:

    int findDays(vector<int> &weights, int cap ) {
        int n = weights.size() ;
        int days = 1, load = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( weights[i] + load > cap ) {
                days += 1 ;
                load = weights[i] ;
            }
            else{
                load += weights[i] ;
            }
        }
        return days ;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size() ;
        int maxi = INT_MIN ;
        int sum = 0 ;
 
        for(int i = 0 ; i< n ; i++ ){
            maxi = max(maxi, weights[i] ) ;
            sum += weights[i] ;
        }

        int low = maxi , high = sum ;

        while( low <= high ) {
            int mid = low + ( high - low ) / 2 ;
            int numberOfDays = findDays(weights, mid ) ;

            if ( numberOfDays <= days ) high = mid - 1 ;
            else low = mid + 1 ;
        }

        return low ;
    }
};