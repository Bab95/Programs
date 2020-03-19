class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,vector<int> > followersList;//user to followers list who's following who who..
    vector<pair<int,int> > tweetsId;
    unordered_map<int,vector<pair<int,int> > > tweets;//user to tweets mapping
    int Index;
    Twitter() {
        Index = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        pair<int,int> tweetpair;
        tweetpair.first = Index;
        ++Index;
        tweetpair.second = tweetId;
        tweets[userId].push_back(tweetpair);
        tweetsId.push_back(tweetpair);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int> > result;
        vector<int> userFollowerList = followersList[userId];

		result.insert(result.end(),tweets[userId].begin(),tweets[userId].end());
        for(int i=0;i<userFollowerList.size();i++){
            result.insert(result.end(),tweets[userFollowerList[i]].begin(),tweets[userFollowerList[i]].end());
        }
        sort(result.begin(),result.end());
        vector<int> final_result;
        int k = 0;
        for(auto itr=result.rbegin();itr!=result.rend();itr++){
            final_result.push_back(itr->second);
            k++;
            if(k==10){
                break;
            }
        }
        return final_result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        if(followersList.find(followerId)==followersList.end()){
            followersList[followerId].push_back(followeeId);
        }else{
            for(auto i=followersList[followerId].begin();i!=followersList[followerId].end();i++){
                if(*i==followeeId){
                    return;
                }
            }
            followersList[followerId].push_back(followeeId);
        }
        //cout<<followerId<<" followed "<<followeeId<<endl;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followersList.find(followerId)==followersList.end()){
            return;
        }else{
            for(auto i=followersList[followerId].begin();i!=followersList[followerId].end();i++){
                if(*i==followeeId){
                    followersList[followerId].erase(i);
                    return;
                }
            }
        }
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


/* TEST CASES

["Twitter","postTweet","follow","follow","getNewsFeed"]
[[],[2,5],[1,2],[1,2],[1]]

["Twitter","postTweet","follow","getNewsFeed"]
[[],[1,5],[1,1],[1]]

["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]


["Twitter","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","follow","follow","follow","follow","follow","getNewsFeed","getNewsFeed","getNewsFeed","getNewsFeed","getNewsFeed"]
[[],[1,3][1,5],[2,6],[3,16],[1,10],[2,11],[3,7],[4,8],[7,12],[1,2],[1,3],[4,3],[4,2],[4,7],[1],[2],[3],[4],[7]]

*/
