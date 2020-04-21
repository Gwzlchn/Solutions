/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.17%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    23.9K
 * Total Submissions: 53.7K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */

// @lc code=start


这种方法背后的想法如下：如果累积总和（由 sum[i]sum[i] 表示加到 i^{th}ith的和）最多两个指数是相同的，那么这些元素之间的元素总和为零。进一步扩展相同的想法，如果累计总和，在索引 ii 和 jj 处相差 kk，即 sum[i] - sum[j] = ksum[i]−sum[j]=k，则位于索引 ii 和 jj 之间的元素之和是 kk。

基于这些想法，可以使用了一个哈希表 mapmap，它用于存储所有可能的索引的累积总和以及相同累加和发生的次数。我们以以下形式存储数据：(sum_isum i​	 ，sum_isum i 的出现次数)。我们遍历数组numsnums并继续寻找累积总和。每当我们遇到一个新的和时，我们在hashmap中创建一个与该总和相对应的新条目。如果再次出现相同的和，我们增加与mapmap中的和相对应的计数。此外，对于遇到的每个总和，我们还确定已经发生 sum-ksum−k 总和的次数，因为它将确定具有总和 kk 的子阵列发生到当前索引的次数。我们将 countcount 增加相同的量。

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cur = 0, res = 0;
        unordered_map<int, int> um;
      	// 注意这里前缀和多了一个0，防止漏掉数组的前缀和刚好等于k的情况
        um[0] = 1;
        for (int num : nums) {
            cur += num;
            res += um.find(cur - k) == um.end() ? 0 : um[cur - k];
            um[cur]++;
        }
        return res;
    }
};



// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
        
//         int len = nums.size();
//         //if(!len) return 0;
//         int cnt = 0;
//         for(int i=0;i<len;i++){
//             int sum = 0;
//             for(int j=i;j<len;j++){
//                 sum += nums[j];
//                 if(sum == k){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
// @lc code=end

