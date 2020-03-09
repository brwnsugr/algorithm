#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        max_number_of_recent_tweets = 10;
        followings = {};
        tweets = {};
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back(make_pair(time,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        unordered_set<int> s;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < tweets[userId].size();++i){
            pq.push(tweets[userId][i]);
        }
        for(auto it = followings[userId].begin(); it!= followings[userId].end(); ++it){
            for(int j = 0; j < tweets[*it].size(); ++j){
                pq.push(tweets[*it][j]);
            }
        }
        for(int k = 0; k < max_number_of_recent_tweets; k++){
            if(pq.empty()) break;
            pair<int, int> elem = pq.top();
            pq.pop();
            res.push_back(elem.second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followings[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followings[followerId].erase(followeeId);
    }
    
private:
    int max_number_of_recent_tweets; // 최대 트윗 리스팅 숫자
    unordered_map<int, set<int>> followings; // follower, followee pair 리스트
    unordered_map<int, vector<pair<int,int>>> tweets; // tweet 글 자료형, 글을 쓴 user_id와 post_id 의 pair 리스트
    int time;
};