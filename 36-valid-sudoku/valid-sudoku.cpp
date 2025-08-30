class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create sets for each row, column, and 3x3 subgrid
        unordered_set<char> rowSet[9];
        unordered_set<char> colSet[9];
        unordered_set<char> boxSet[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];
                if (current == '.') continue;

                // Calculate box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check for duplicates
                if (rowSet[i].count(current) || 
                    colSet[j].count(current) || 
                    boxSet[boxIndex].count(current)) {
                    return false;
                }

                // Add to sets
                rowSet[i].insert(current);
                colSet[j].insert(current);
                boxSet[boxIndex].insert(current);
            }
        }

        return true;
    }
};
