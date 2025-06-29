class Twitter {
private:
    unordered_map<int, set<int>> fo;
    unordered_map<int, vector<pair<int, int>>> t;
    long long time;

public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (auto& tweet : t[userId]) pq.push(tweet);
        for (int u : fo[userId])
            for (auto& tweet : t[u]) pq.push(tweet);

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            fo[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};
