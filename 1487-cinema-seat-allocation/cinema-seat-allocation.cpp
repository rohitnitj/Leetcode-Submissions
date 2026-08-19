#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row_masks;
        
        for (const auto& seat : reservedSeats) {
            int r = seat[0];
            int c = seat[1];
            row_masks[r] |= (1 << c);
        }
        
        int max_families = (n - row_masks.size()) * 2;
        
        for (auto const& [row, mask] : row_masks) {
            bool left_free = (mask & 60) == 0;      
            bool right_free = (mask & 960) == 0;    
            bool middle_free = (mask & 240) == 0;   
            
            if (left_free && right_free) {
                max_families += 2;
            } else if (left_free || right_free || middle_free) {
                max_families += 1;
            }
        }
        
        return max_families;
    }
};