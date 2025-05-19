class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};

    bool check(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int k) {
        int n = board.size();
        int m = board[0].size();

        if (board[r][c] != word[k]) return false;
        if (k == word.size() - 1) return true;

        char temp = board[r][c];  
        board[r][c] = '#';         

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (check(nr, nc, n, m) && board[nr][nc] != '#') {
                if (dfs(board, nr, nc, word, k + 1)) {
                    board[r][c] = temp; 
                    return true;
                }
            }
        }

        board[r][c] = temp; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }

        return false;
    }
};
