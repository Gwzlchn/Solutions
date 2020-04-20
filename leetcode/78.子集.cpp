/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (73.97%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    25.8K
 * Total Submissions: 34.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
 //位运算，顺序无关紧要
// √ Accepted
//   √ 10/10 cases passed (8 ms)
//   √ Your runtime beats 93.12 % of cpp submissions
//   √ Your memory usage beats 89.22 % of cpp submissions (8.9 MB)
### 解题思路
思路就参考第一个评论“”
![image.png](https://pic.leetcode-cn.com/6c3836cff1ac036fccdc899e9eadd72e2c59afe32733877c756dc24bf32b9f71-image.png)

直白点说就是这样：
以[1,2,3] 为例
起始，插入空集
step1 : 复制空集，将 1 插入末尾。like this  [[], [1]];
step2 : 复制上面两个集合，复制同时将 2 插入。 [[], [1], [2], [1, 2]];
step3 : 复制上面四个集合，复制同时将 3 插入。 [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sub_set{{}};

        int len = nums.size();
        for(auto& num:nums){
            int n = sub_set.size();
            for(int j=0;j<n;j++){
                sub_set.push_back(sub_set[j]);
                sub_set.back().push_back(num);

            }
        }

        return sub_set;
    }
};
```
