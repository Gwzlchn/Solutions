class Solution {
public:
    int get_digit_sum(int x,int y){
        int res = 0;
        for(;x;x/=10)
            res += x%10;
        for(;y;y/=10)
            res += y%10;
        return res;
    }
    int movingCount(int m, int n, int k) {
        int res = 1;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> bfs;

        bfs.push({0,0});
        visited[0][0] = true;

        int dx[] = {1,0};
        int dy[] = {0,1};

        while(!bfs.empty()){
            auto cur = bfs.front();
            bfs.pop();
            

            int cur_x = cur.first;
            int cur_y = cur.second;
            //cout<<cur_x<<" "<<cur_y<<endl;
            for(int i=0;i<2;i++){
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];

               // cout<<new_x<<" "<<new_y<<endl;

                if(is_valid(m, n, k, new_x, new_y) && !visited[new_x][new_y]){
                    //cout<<new_x<<" "<<new_y<<endl;

                    bfs.push({new_x,new_y});
                    visited[new_x][new_y] = true;
                    res++;
                }
            }
        }
        return res;
     }

     bool is_valid(int m,int n,int k,int cur_x,int cur_y){
         //cout<<cur_x<<" "<<cur_y<<" "<<m<<" "<<n<<endl;
         bool a =  cur_x>=0 && cur_x<m && cur_y>=0 && cur_y<n ;
         //if(a) cout<<"a";
         bool b =  get_digit_sum(cur_x,cur_y) <= k ;
        // cout<<get_digit_sum(cur_x, cur_y);
        // if(b) cout<<"b";
         return a&&b;

     }
};