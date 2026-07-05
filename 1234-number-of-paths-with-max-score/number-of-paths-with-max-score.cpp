class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<int>> max_score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        
        max_score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;
        
        int dirs[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (ways[r][c] == 0) continue;
                
                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    if (nr >= 0 && nc >= 0 && board[nr][nc] != 'X') {
                        int val = (board[nr][nc] == 'E') ? 0 : (board[nr][nc] - '0');
                        int current_score = max_score[r][c] + val;
                        
                        if (current_score > max_score[nr][nc]) {
                            max_score[nr][nc] = current_score;
                            ways[nr][nc] = ways[r][c];
                        } 
                        else if (current_score == max_score[nr][nc]) {
                            ways[nr][nc] = (ways[nr][nc] + ways[r][c]) % MOD;
                        }
                    }
                }
            }
        }
        
        if (max_score[0][0] == -1) {
            return {0, 0};
        }
        
        return {max_score[0][0], ways[0][0]};
    }
};