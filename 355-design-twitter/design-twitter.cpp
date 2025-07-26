class Twitter {
public:
    int time;
    unordered_map<int,unordered_set<int>> m; //stores followers
    unordered_map<int,vector<pair<int,int>>> n; //user id {time,tweetId}
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        n[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; //this stores the most recent tweets because pq sort by time stamp that is maximum time will be at the top
//because the tweet with the maximum time is the most recent id
        for(auto ele:n[userId]) pq.push(ele); //ele is {time,tweetId}
        for(auto ele:m[userId]){
            for(auto i:n[ele]) pq.push(i); //this will push the tweets of those id who is followed by userId
        }

        vector<int> ans;
        int count=10;
        while(pq.empty()!=1 and count>0){
            ans.push_back(pq.top().second);
            pq.pop();
            count--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m[followerId].erase(followeeId);
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