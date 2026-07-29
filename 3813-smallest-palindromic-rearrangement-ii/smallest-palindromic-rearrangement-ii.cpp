#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to calculate distinct permutations of the remaining multiset
    long long calcPerms(const vector<int>& counts, int limit) {
        // Precompute nCr values up to 5000 using local static to run only once per session
        static vector<vector<int>> ncr;
        static bool initialized = false;
        
        if (!initialized) {
            ncr.assign(5005, vector<int>(5005, 0));
            for (int i = 0; i <= 5000; ++i) {
                ncr[i][0] = 1;
                for (int j = 1; j <= i; ++j) {
                    long long val = (long long)ncr[i-1][j-1] + ncr[i-1][j];
                    if (val > 1000005) val = 1000005; // Cap slightly above max k (10^6)
                    ncr[i][j] = val;
                }
            }
            initialized = true;
        }
        
        long long res = 1;
        int remaining_len = 0;
        
        // Find total remaining length
        for (int c : counts) {
            remaining_len += c;
        }
        
        // Permutations for a multiset is product of combinations:
        // C(L, c0) * C(L - c0, c1) * ...
        for (int c : counts) {
            if (c == 0) continue;
            
            long long ways = ncr[remaining_len][c];
            
            // Avoid overflow before multiplication
            if (ways > limit / res + 1) return limit + 1; 
            
            res *= ways;
            if (res > limit) return limit + 1;
            
            remaining_len -= c;
        }
        
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        vector<int> counts(26, 0);
        string mid = "";
        int half_len = 0;
        
        // Determine characters for the first half and the odd middle character (if any)
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid += (char)('a' + i);
            }
            counts[i] = freq[i] / 2;
            half_len += counts[i];
        }
        
        // If the total valid permutations are strictly less than k, return empty string
        long long total = calcPerms(counts, k);
        if (total < k) return "";
        
        string first_half = "";
        
        // Greedily build the first half
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (counts[c] > 0) {
                    counts[c]--; // Temporarily place this character
                    
                    long long perms = calcPerms(counts, k);
                    
                    if (perms >= k) {
                        // The k-th permutation lies in this branch
                        first_half += (char)('a' + c);
                        break; 
                    } else {
                        // Skip this branch, decrease k by the skipped permutations
                        k -= perms;
                        counts[c]++; // Backtrack and try next character
                    }
                }
            }
        }
        
        // Build the final full palindrome
        string res = first_half + mid;
        for (int i = half_len - 1; i >= 0; --i) {
            res += first_half[i];
        }
        
        return res;
    }
};