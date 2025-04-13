class Twitter {

private:
    
    int timer;
    unordered_map<int,set<int>>follower;
    unordered_map<int,vector<pair<int,int>>>user_tweet;

public:
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweet[userId].push_back({tweetId,++timer});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto it:user_tweet[userId])
            pq.push({it.second,it.first});
        for(auto it:follower[userId])
        {
            for(auto i:user_tweet[it])
                pq.push({i.second,i.first});
        }
        int cnt=0;
        while(!pq.empty() && cnt<10)
        {
            ++cnt;
            auto t=pq.top();
            pq.pop();
            ans.push_back(t.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */