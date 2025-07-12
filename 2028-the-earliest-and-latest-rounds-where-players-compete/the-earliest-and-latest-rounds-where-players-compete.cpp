class Solution {
public:
    // Memoization: key is pair of players and round number
    map<tuple<int, int, vector<int>>, pair<int, int>> memo;

    pair<int, int> dfs(vector<int> players, int firstPlayer, int secondPlayer, int round) {
        int n = players.size();
        
        // Check if they face each other in this round
        for (int i = 0; i < n / 2; ++i) {
            int a = players[i], b = players[n - 1 - i];
            if ((a == firstPlayer && b == secondPlayer) || (a == secondPlayer && b == firstPlayer)) {
                return {round, round};
            }
        }

        auto key = make_tuple(firstPlayer, secondPlayer, players);
        if (memo.count(key)) return memo[key];

        vector<pair<int, int>> matches;
        for (int i = 0; i < n / 2; ++i) {
            matches.push_back({players[i], players[n - 1 - i]});
        }
        vector<int> middle;
        if (n % 2 == 1) middle.push_back(players[n / 2]);

        vector<vector<int>> all_next_rounds;
        vector<int> current;

        function<void(int)> backtrack = [&](int i) {
            if (i == matches.size()) {
                vector<int> next = current;
                next.insert(next.end(), middle.begin(), middle.end());
                sort(next.begin(), next.end());
                all_next_rounds.push_back(next);
                return;
            }

            int a = matches[i].first, b = matches[i].second;
            if (a == firstPlayer || a == secondPlayer) {
                current.push_back(a);
                backtrack(i + 1);
                current.pop_back();
            } else if (b == firstPlayer || b == secondPlayer) {
                current.push_back(b);
                backtrack(i + 1);
                current.pop_back();
            } else {
                // try both
                current.push_back(a);
                backtrack(i + 1);
                current.pop_back();

                current.push_back(b);
                backtrack(i + 1);
                current.pop_back();
            }
        };

        backtrack(0);

        int min_round = INT_MAX, max_round = INT_MIN;

        for (auto& next_players : all_next_rounds) {
            auto res = dfs(next_players, firstPlayer, secondPlayer, round + 1);
            min_round = min(min_round, res.first);
            max_round = max(max_round, res.second);
        }

        return memo[key] = {min_round, max_round};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> players(n);
        iota(players.begin(), players.end(), 1); // [1, 2, ..., n]
        auto res = dfs(players, firstPlayer, secondPlayer, 1);
        return {res.first, res.second};
    }
};
