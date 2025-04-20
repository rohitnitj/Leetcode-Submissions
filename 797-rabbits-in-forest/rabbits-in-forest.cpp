class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mpp ;
        for( int a : answers ) mpp[a]++ ;

        int cnt =0 ;
        for( auto &m : mpp ) {
            double c = m.first+1, f = m.second ;
            cnt += (ceil(f/c) * c) ;
        }

        return cnt ;
    }
};
