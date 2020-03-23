class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> inter;
        for(auto i : intervals){
            inter.push_back({i[0],1});
            inter.push_back({i[1],-1});
        }

        sort(inter.begin(),inter.end(),
        [](auto& p1,auto& p2)->bool{return p1.first!=p2.first ? p1.first<p2.first : p1.second < p2.second ; });

        int cnt = 0;
        int max = 0;
        for(auto& i:inter){
            cnt += i.second;
            max = max>cnt? max:cnt;
        }
        return max;
    }
};


