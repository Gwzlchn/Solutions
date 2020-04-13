/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 *
 * https://leetcode-cn.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (37.07%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 19.9K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * 
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
 * 
 * 
 * postTweet(userId, tweetId): 创建一条新的推文
 * getNewsFeed(userId):
 * 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
 * follow(followerId, followeeId): 关注一个用户
 * unfollow(followerId, followeeId): 取消关注一个用户
 * 
 * 
 * 示例:
 * 
 * 
 * Twitter twitter = new Twitter();
 * 
 * // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1关注了用户2.
 * twitter.follow(1, 2);
 * 
 * // 用户2发送了一个新推文 (推文id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
 * // 推文id6应当在推文id5之前，因为它是在5之后发送的.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1取消关注了用户2.
 * twitter.unfollow(1, 2);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * // 因为用户1已经不再关注用户2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */

// @lc code=start
class Twitter {
private:
    unordered_map<int,set<int>> m_user_follow;
    //key->user id
    //value-> time,tweet
    unordered_map<int,deque<pair<int,int>>> m_user_post;
    int m_time_stamp ;
    int m_max_post_capacity;
public:
    /** Initialize your data structure here. */
    Twitter() {
        m_time_stamp = 0;
        m_max_post_capacity = 10;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto iter = m_user_post.find(userId);
        if(iter!=m_user_post.end() && iter->second.size() >= m_max_post_capacity){
            iter->second.pop_front();
        }
        m_user_post[userId].push_back({m_time_stamp,tweetId});
        m_time_stamp++;
        
        return;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
         //自己发送的推文
        vector<pair<int,int>> user_id_follow_tweet(m_user_post[userId].begin(),m_user_post[userId].end());

        auto iter = m_user_follow.find(userId);
        if(iter!=m_user_follow.end()){
            for(auto& f : iter->second){
                user_id_follow_tweet.insert(user_id_follow_tweet.end(),m_user_post[f].begin(),m_user_post[f].end());
            }
        }

        vector<int> res;
        //对所有推文进行部分排序,同时将pair<int,int>中的第二个元素提出来
        if(user_id_follow_tweet.size() >= m_max_post_capacity){
             std::partial_sort(user_id_follow_tweet.begin(),user_id_follow_tweet.begin()+m_max_post_capacity,\
                    user_id_follow_tweet.end(),std::greater<>());
            std::transform(user_id_follow_tweet.begin(),user_id_follow_tweet.begin() + m_max_post_capacity,\
                        back_inserter(res),[](auto& p1){return p1.second;});
        }else{
            sort(user_id_follow_tweet.begin(),user_id_follow_tweet.end(),std::greater<>());
            std::transform(user_id_follow_tweet.begin(),user_id_follow_tweet.end(),\
                        back_inserter(res),[](auto& p1){return p1.second;});
        }


        return res;

    }

  
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        //自己关注自己的用例
        if(followerId == followeeId) return;
        m_user_follow[followerId].insert(followeeId);

    }



    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto iter = m_user_follow.find(followerId);
        if(iter!=m_user_follow.end()){
            auto& follow_set = iter->second;
            auto followee_iter = find(follow_set.begin(),follow_set.end(),followeeId);
            if(followee_iter!=follow_set.end()){
                follow_set.erase(followee_iter);
            }
        }
        return;
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

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

