// 题目描述
// As an emergency rescue team leader of a city, you are given a special map of your country.  
//The map shows several scattered cities connected by some roads.  
// Amount of rescue teams in each city and the length of each road between any pair of 
// cities are marked on the map.  When there is an emergency call to you from some other city, 
// your job is to lead your men to the place as quickly as possible, and at the mean time, 
// call up as many hands on the way as possible.

// 输入描述:
// Each input file contains one test case. For each test case, the first line contains 
// 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), 
// M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively.  
// The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city.  
// Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected 
// by a road and the length of that road, respectively.  
// It is guaranteed that there exists at least one path from C1 to C2.


// 输出描述:
// For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2,
//  and the maximum amount of rescue teams you can possibly gather.
// All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

// 输入例子:
// 5 6 0 2
// 1 2 1 5 3
// 0 1 1
// 0 2 2
// 0 3 1
// 1 2 1
// 2 4 1
// 3 4 1

// 输出例子:
// 2 4
#include<cstdio>
#include<algorithm>
using namespace std;




int main() {

	const long inf = 999999;
	const int max_city = 505;
	int graph[max_city][max_city] = { 0 };
	int rescue_i[max_city] = { 0 };
	bool visited[max_city] = { false };

	int rescue[max_city] = { 0 };//从起点到每个节点i的救援队
	int graph_distance[max_city] = { 0 };//从起点到每个节点最短路径
	int num_shortest_path[max_city] = { 0 };//从起点到每个节点最短路径数量


	int cities = 0, roads = 0, from = 0, to = 0;
	scanf("%d%d%d%d", &cities, &roads, &from, &to);

	for (int i = 0; i < cities; i++) {
		int resc = 0;
		scanf("%d", &resc);
		rescue_i[i] = resc;
	}
	fill(graph[0], graph[0] + max_city * max_city, inf);
	fill(graph_distance, graph_distance + max_city, inf);
	for (int i = 0; i < roads; i++) {
		int cfrom = 0, cto = 0, cost = 0;
		scanf("%d%d%d", &cfrom, &cto, &cost);
		graph[cfrom][cto] = cost;
		graph[cto][cfrom] = cost;
	}

	graph_distance[from] = 0;
	rescue[from] = rescue_i[from];
	num_shortest_path[from] = 1;
	//dijstra
	for (int i = 0; i < cities; i++) {
        printf("%d %d %d\t", i,num_shortest_path[i], rescue[i]);
		int u = -1, minn = inf;
		for (int j = 0; j < cities ; j++) {
            if( visited[j] == false && graph_distance[j] < minn)
			u = j; minn = graph_distance[j];
		}
		if (u == -1) break;
		visited[u] = true;
		for (int j = 0; j < cities; j++) {
			if (visited[j] == false && graph[u][j] != inf) {
				
				if (graph_distance[u] + graph[u][j] < graph_distance[j]) {
                    //走节点j
					graph_distance[j] = graph_distance[u] + graph[u][j];
					num_shortest_path[j] = num_shortest_path[u];
					rescue[j] = rescue[u] + rescue_i[j];
					
				}//经不经过j距离都一样，取最大救援队数
				else if (graph_distance[u] + graph[u][j] == graph_distance[j]) {
					num_shortest_path[j] += num_shortest_path[u];
					if (rescue[u] + rescue_i[j] > rescue[j]) {
						rescue[j] = rescue[u] + rescue_i[j];
					}
				}
			}
		}
        
	}
		printf("%d %d", num_shortest_path[to], rescue[to]);
		return 0;
}


