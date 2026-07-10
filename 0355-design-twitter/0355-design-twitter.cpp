class Twitter {
private:
    int timestamp;

    struct Tweet{
        int id;
        int time;
    };
    unordered_map<int , vector<Tweet>> tweets;
    unordered_map<int , unordered_set<int>> following;
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId , timestamp++});      
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int , int>> maxHeap;

        for(const auto& tweet : tweets[userId]){
            maxHeap.push({tweet.time , tweet.id});
        }

        for(int followeeId : following[userId]){
            if(followeeId == userId) continue;
            for(const auto& tweet : tweets[followeeId]){
                maxHeap.push({tweet.time , tweet.id});
            }
        }

        vector<int> feed;
        int count = 0; 

        while(!maxHeap.empty() && count < 10){
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        return feed; 
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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