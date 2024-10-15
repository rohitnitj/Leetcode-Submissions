class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size() ;
        sort(asteroids.begin(), asteroids.end() ) ;

        unsigned long long current_mass = mass ;
        for( int i = 0 ; i < n ; i++ ) {
            if( current_mass < asteroids[i] ) return false ;
            current_mass += asteroids[i] ;
        }

        return true;
    }
};