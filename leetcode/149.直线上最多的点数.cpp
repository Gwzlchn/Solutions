/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (20.76%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 50.3K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 * 
 * 示例 1:
 * 
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 */

class Solution {
public:

//求两个数最小公倍数
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

//在一个点的集合中，统计点集中所有的点出现次数
int points_repeat_cnt(set<pair<int, int>>& points_set, map<pair<int, int>, int>& unique_point) 
{
	int cnt = 0;
	for (auto& p : points_set) {
		// 累加这个点的出现次数
		cnt += unique_point[p];
	}
	return cnt;
}

int maxPoints(vector<vector<int>>& points) {
	int len = points.size();
	if (len == 0 || len == 1) return len;

	// key -> tuple<int,int,long long> => Ax + By + C = 0 记录的是 A B C
	// value -> 坐标（i,j）即 出现在这条线上的点集
	map<tuple<int, int, long long>, set<pair<int, int>>> point_in_line;

	// 点集去重，并计数
	map<pair<int, int>, int> unique_point;
	for (auto& p : points) {
		unique_point[{p[0], p[1]}]++;
	}


	for (auto i_iter = unique_point.cbegin(); i_iter != unique_point.cend(); i_iter++)
	{
		auto& p1 = i_iter->first;
		int x1 = p1.first, y1 = p1.second;

		for (auto j_iter = (i_iter); j_iter != unique_point.cend(); j_iter++)
		{
			// map 的迭代器不允许加1 ,但实际上两个相同的点计算一般式没有意义。
			if (j_iter == i_iter) continue;

			auto& p2 = j_iter->first;
			int x2 = p2.first, y2 = p2.second;

			int cur_A = y2 - y1;
			int cur_B = x2 - x1;
			long long cur_C = long(x2) * long(y1) - long(x1) * long(y2);
			//tuple 存放约分后的 A B C
			tuple<int, int, long long> temp;
			if (cur_A == 0 && cur_B == 0) {
				temp = { cur_A, cur_B, 0 };
			}
			else {
				// 对 ABC 三个数约分
				int cur_gcd = GCD(GCD(cur_A, cur_B), cur_C);

				temp = { cur_A / cur_gcd, cur_B / cur_gcd, cur_C / cur_gcd };
			}

			//这两个点 都经过了这条Ax + By + C = 0线
			point_in_line[temp].insert(p1);
			point_in_line[temp].insert(p2);
		}

	}

	// 在一条线上出现 所有点的 数量，这一步是考虑 点会重复
	int max_points_in_one_line = -1;
	//map<tuple<int, int, long long>, int> point_in_line_cnt;
	for (auto& p : point_in_line) 
	{
		int cur_points_in_one_line_cnt = points_repeat_cnt(p.second, unique_point);
		max_points_in_one_line = max(max_points_in_one_line, cur_points_in_one_line_cnt);
	}

	// 按照 上面统计的数量，对 map（point_in_line_cnt） 中的value 值排序，取最大值
	if (max_points_in_one_line != -1)
	{
		return max_points_in_one_line;
	}

	// 如果 线的集合为空，则所有点均为同一个点
	return len;


}
};
// @lc code=end

