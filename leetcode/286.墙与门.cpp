class Solution {
public:
    queue<pair<int, int>> q; // 宽搜队列
    int dirR[4] = {-1,0, 1, 0};
    int dirC[4] = {0, 1, 0, -1};
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i< rooms.size(); i++){
            for (int j =0; j< rooms[0].size(); j++){
                if (rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        bfs(rooms);
    }
   
    void bfs(vector<vector<int>>& rooms){
        int step = 0;
        unordered_set<string> st;
        while(!q.empty()){
            int k = q.size();
            step++;
            for (int i = 0; i< k; i++){
                auto f = q.front();
                q.pop();
                for (int d = 0; d < 4; d++){
                    int r = dirR[d] + f.first;
                    int c = dirC[d] + f.second;
                    if (r < 0 || r >= rooms.size() || c < 0 || c>= rooms[0].size()) continue;
                    if (rooms[r][c] == -1 || rooms[r][c] == 0) continue;
                    if (rooms[r][c] > step) {
                        rooms[r][c] = step;
                        q.push({r, c});
                    }
                }
            }
        }
    }
};
