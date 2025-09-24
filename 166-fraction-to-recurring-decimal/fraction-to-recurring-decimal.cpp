class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Convert to long long to handle overflow (like INT_MIN / -1)
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);
        
        // Integer part
        result += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return result;  // No fractional part
        
        result += ".";
        
        // Map remainder → index in result string
        unordered_map<long long, int> seen;
        
        while (rem != 0) {
            if (seen.count(rem)) {
                // Insert "(" at position where this remainder first appeared
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }
            seen[rem] = result.size();
            
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }
        
        return result;
    }
};
