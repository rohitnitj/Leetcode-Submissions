typedef long long ll ;

class Solution {
private:    
    bool check(vector<int> &arr, int r, ll mp, int extra ) {
        int n = arr.size() ;
        ll sum = 0 ;
        for( int i = 0 ; i < r ; i++ ) sum += arr[i] ;

        vector<int> add(n, 0 ) ;
        for( int i = 0 ; i < n ; i++ ) {
            if( i + r < n ) sum += arr[i+r] ;
            if( sum < mp ) {
                ll need = mp - sum ;
                if( need > extra ) return false ;
                add[min(n-1, i+r )] += need ;
                sum = mp ;
                extra -= need ;
            }
            if( i - r >= 0 ) {
                sum -= ( arr[i-r] + add[i-r] ) ;
            }
        }

        return true ;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        ll left = 0;
        ll right = accumulate(stations.begin(), stations.end(), 0ll + k ) ;
        ll ans = 0;

        while( left <= right ) {
            ll mid = left + ( right - left ) / 2 ;
            if( check(stations, r, mid, k ) ) {
                ans = mid;
                left = mid + 1 ;
            }
            else{
                right = mid - 1 ;
            }
        }

        return ans ;
    }
};