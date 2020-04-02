class UndergroundSystem {

private:

    //历史行程表
    //key -> src,dst
    //value -> 人数，时间和
    map<pair<string,string>,pair<int64_t,int64_t>> history_map;
    //一个人的当前行程
    //key->id
    //value-> src,time
    map<int,pair<string,int>> passenger_map;
public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        passenger_map[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto iter = passenger_map.find(id);
        int time = t - iter->second.second;
        auto from_to = make_pair(iter->second.first,stationName);
        history_map[from_to].first++;
        history_map[from_to].second += time;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto iter = history_map.find({startStation,endStation});
        return (double)iter->second.second / iter->second.first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */