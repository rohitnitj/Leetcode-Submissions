class Solution {
public:
    double myPow(double x, int n) {
        return solve(x, n);
    }
    
    double solve(double x, long long n) {
        if (n == 0) return 1.0;
        if (n < 0) return 1.0 / solve(x, -n);
        
        double half = solve(x, n / 2);
        
        if (n % 2 == 0) return half * half;
        return half * half * x;
    }
};