class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // avoid duplicates
        }

        board[i][j] = '#';  // mark as visited

        if (i > 0) dfs(board, i - 1, j, node, result);
        if (j > 0) dfs(board, i, j - 1, node, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, node, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, node, result);

        board[i][j] = c;  // backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        // Build Trie
        for (const string& word : words)
            insert(root, word);

        vector<string> result;
        int m = board.size(), n = board[0].size();

        // Start DFS from each cell
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, root, result);

        return result;
    }
};
