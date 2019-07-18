/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 *
 * https://leetcode-cn.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (58.59%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    2.4K
 * Total Submissions: 4.2K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * 实现一个 MapSum 类里的两个方法，insert 和 sum。
 * 
 * 对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。
 * 
 * 对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。
 * 
 * 示例 1:
 * 
 * 输入: insert("apple", 3), 输出: Null
 * 输入: sum("ap"), 输出: 3
 * 输入: insert("app", 2), 输出: Null
 * 输入: sum("ap"), 输出: 5
 * 
 * 
 */
 //STL里面的mismatch 用来匹配前缀
//  √ Accepted
//   √ 30/30 cases passed (12 ms)
//   √ Your runtime beats 68.28 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (9.2 MB)

//用string find来匹配前缀
//  √ Accepted
//   √ 30/30 cases passed (8 ms)
//   √ Your runtime beats 88.71 % of cpp submissions
//   √ Your memory usage beats 95.83 % of cpp submissions (9.4 MB)
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        sum_map[key] = val;
    }
    
    int sum(string prefix) {
        int ret = 0;
        for(auto iter = sum_map.begin();iter!=sum_map.end();iter++){
            auto match = std::mismatch(prefix.begin(),prefix.end(),iter->first.begin());
            if(match.first == prefix.end() ){
                ret += iter->second;
            }
        }
        return ret;
    }
    //  auto it = sum_map.lower_bound(prefix);
    //     while(it != sum_map.end() && it->first.find(prefix) == 0) {
    //         ret += it->second;
    //         ++it;
    //     }

    map<string,int> sum_map;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

