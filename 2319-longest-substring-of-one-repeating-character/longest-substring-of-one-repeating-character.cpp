// Segment Tree Node
struct Node {
    int max_len;
    int pre_len;
    int suf_len;
    char left_char;
    char right_char;
    int size;
};

class Solution {
    vector<Node> tree;
    string str;

    // Helper function to merge two segment tree nodes
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.left_char = left.left_char;
        res.right_char = right.right_char;

        // Calculate prefix length
        res.pre_len = left.pre_len;
        if (left.pre_len == left.size && left.right_char == right.left_char) {
            res.pre_len += right.pre_len;
        }

        // Calculate suffix length
        res.suf_len = right.suf_len;
        if (right.suf_len == right.size && left.right_char == right.left_char) {
            res.suf_len += left.suf_len;
        }

        // Calculate max continuous length
        res.max_len = max(left.max_len, right.max_len);
        if (left.right_char == right.left_char) {
            res.max_len = max(res.max_len, left.suf_len + right.pre_len);
        }

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, str[start], str[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {1, 1, 1, c, c, 1};
            str[idx] = c;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        tree.resize(4 * n + 1);
        
        // Build the initial segment tree
        build(1, 0, n - 1);

        vector<int> ans;
        int k = queryCharacters.length();
        ans.reserve(k);
        
        // Process each query
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            // The root node contains the max continuous length for the whole string
            ans.push_back(tree[1].max_len);
        }
        
        return ans;
    }
};