/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 *
 * https://leetcode-cn.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 20.6K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 N 个网络节点，标记为 1 到 N。
 * 
 * 给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w
 * 是一个信号从源节点传递到目标节点的时间。
 * 
 * 现在，我们从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * 输出：2
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * N 的范围在 [1, 100] 之间。
 * K 的范围在 [1, N] 之间。
 * times 的长度在 [1, 6000] 之间。
 * 所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int INF = 32767;

        vector<vector<int>> graph(N,vector<int>(N,INF));

        for(auto& edge:times){
            //[from][to] = cost
            graph[edge[0]-1][edge[1]-1] = edge[2];
        }

        //迪杰斯特拉算法
        vector<bool> visited(N,false);
        vector<int>& distance = graph[K-1];
        int max_dis = INT_MIN;

        distance[K-1] = 0;
        visited[K-1] = true;

        for(int k=1;k<N;k++){

            //找到当前未访问节点中最小的那条边
            int cur_min_idx = 0;
            int cur_min_cost = INT_MAX;
            for(int i=0;i<N;i++){
                if(!visited[i]  &&distance[i] < cur_min_cost){
                    cur_min_idx = i;
                    cur_min_cost =  distance[i];
                }
            }
            if(cur_min_cost == INF) continue;
            
            cout<<cur_min_idx<<" "<<cur_min_cost<<endl;
            //更新起点到这个值的最小值
            distance[cur_min_idx] = cur_min_cost;
            visited[cur_min_idx] = true;
            max_dis = max(max_dis,cur_min_cost);

            //如果 起点 -> 这个点 —> 下一个未被访问点距离更小，更新 起点-> 下一个点的距离值
            for(int i=0;i<N;i++){
                if(!visited[i] && cur_min_cost + graph[cur_min_idx][i] < distance[i]){
                    distance[i] = cur_min_cost + graph[cur_min_idx][i];
                }
            }


        }

        bool all_visited = std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });


        return all_visited? max_dis:-1;
    }
};
// @lc code=end

