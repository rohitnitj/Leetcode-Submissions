class Solution {
    int memo[305][27];

    int getDist(int a, int b) {
        if (a == 26) return 0; 
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int solve(int i, int other, const string& word) {
        if (i == word.length()) return 0;
        
        if (memo[i][other] != -1) return memo[i][other];

        int target = word[i] - 'A';
        int prev = word[i - 1] - 'A';

        int cost1 = getDist(prev, target) + solve(i + 1, other, word);

        int cost2 = getDist(other, target) + solve(i + 1, prev, word);

        return memo[i][other] = min(cost1, cost2);
    }

public:
    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
        
        return solve(1, 26, word);
    }
};