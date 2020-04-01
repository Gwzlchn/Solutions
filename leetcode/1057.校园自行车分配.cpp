class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        struct combination{
            int worker=0;
            int bike = 0;
            int distance =0;
            bool operator <(const combination& com) const {
                if(this->distance != com.distance){
                    return this->distance > com.distance;
                }else{
                    return this->bike > com.bike;
                }
            }
            combination(int w,int b,int d):worker(w),bike(b),distance(d){}
        };
        //key dis         value-><bike,worker>
        map<int,vector<pair<int,int>>> com_map;
        for(int i=0;i<bikes.size();i++){
            for(int j=0;j<workers.size();j++){
                int dis = abs(workers[j][0] - bikes[i][0]) + abs(workers[j][1] - bikes[i][1]);
                //cout<<dis<<endl;
                com_map[dis].push_back({i,j});
            }
        }

        vector<bool> worker_assigned(workers.size(),false);
        vector<bool> bike_assigned(bikes.size(),false);
        vector<int> res_assigned(workers.size(),-1);

       for(auto iter = com_map.begin();iter!=com_map.end();iter++){

            int dis = iter->first;
            for(auto vec = iter->second.begin();vec!=iter->second.end();vec++){
                int bike = vec->first;
                int worker = vec->second;
                if(worker_assigned[worker] || bike_assigned[bike])
                    continue;
                res_assigned[worker] = bike;
                worker_assigned[worker] = true;
                bike_assigned[bike] = true;
            }
            
           // cout<<cur.bike<<" "<<cur.worker<<" "<<cur.distance<<endl;
            

        }

        return res_assigned;
    }
};