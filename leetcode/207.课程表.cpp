/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (49.66%)
 * Likes:    269
 * Dislikes: 0
 * Total Accepted:    30.3K
 * Total Submissions: 61K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
 * 
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 2, [[1,0]] 
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 * 
 * 示例 2:
 * 
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,set<int>>mp;
        vector<int>indegree(numCourses+1,0);
        for(auto v:prerequisites){
            int a=v[1];
            int b=v[0];
            mp[a].insert(b);//构建a-->b的有向图
            ++indegree[b];//初始化入度
        }
        //拓扑排序，采用的是队列，存放的是入度为0的点，即准备释放的点。
        queue<int>que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int v=que.front();
            que.pop();
            ++count;
            //下面就是将出队之后，与那个点相邻的点入度减少一个，其中入度为0的点，入队列
            auto x=mp[v];//x是一个数组
            for(auto t:x){
                indegree[t]--;
                if(indegree[t]==0){
                    que.push(t);
                }
            }

        }
        return count==numCourses;
    }
};


// @lc code=end

