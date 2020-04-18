#include<bits/stdc++.h>


using namespace std;

struct moon_cake{
    double price;
    double total_amount;
    double total_price;
};

int main(){
    int kinds,demand;
    cin>>kinds>>demand;
    vector<moon_cake> moon_vec(kinds);
    for(int i=0;i<kinds;i++) scanf("%lf",&moon_vec[i].total_amount);
    for(int i=0;i<kinds;i++) {
        scanf("%lf",&moon_vec[i].total_price);
        moon_vec[i].price = moon_vec[i].total_price / moon_vec[i].total_amount;
    }
    sort(moon_vec.begin(),moon_vec.end(),
        [](auto& m1,auto& m2){return m1.price < m2.price;});
    
    double total_profit;
    while(demand && !moon_vec.empty()){
        auto cur_highest = moon_vec.back();
        if(demand >= cur_highest.total_amount){
            total_profit += cur_highest.total_price;
            demand -= cur_highest.total_amount;
        }else{
            total_profit += cur_highest.price * demand;
            demand = 0;
        }
        moon_vec.pop_back();
    }
    printf("%.2lf",total_profit);
    return 0;

   



}