// 题目描述
// Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University.  Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test.  Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

// 输入描述:
// Each input file contains one test case.  For each case, the first line contains a positive number N (<=100), the number of test locations.  Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines  containing the registration number (a 13-digit number) and the total score of each testee.  All the numbers in a line are separated by a space.


// 输出描述:
// For each test case, first print in one line the total number of testees.  Then print the final ranklist in the following format:
// registration_number final_rank location_number local_rank
// The locations are numbered from 1 to N.  The output must be sorted in nondecreasing order of the final ranks.  The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

// 输入例子:
// 2
// 5
// 1234567890001 95
// 1234567890005 100
// 1234567890003 95
// 1234567890002 77
// 1234567890004 85
// 4
// 1234567890013 65
// 1234567890011 25
// 1234567890014 100
// 1234567890012 85

// 输出例子:
// 9
// 1234567890005 1 1 1
// 1234567890014 1 2 1
// 1234567890001 3 1 2
// 1234567890003 3 1 2
// 1234567890004 5 1 4
// 1234567890012 5 2 2
// 1234567890002 7 1 5
// 1234567890013 8 2 3
// 1234567890011 9 2 4




#include<vector>
#include <algorithm>
#include<cstdio>
using namespace std;

struct stu{
    long long id;
    int score,room_rank,total_rank,room;
};

int cmp(stu s1,stu s2){
    if(s1.score == s2.score){
        return s1.id < s2.id;
    }
    return s1.score>s2.score;
}

int main(){
    int rooms = 0;
    scanf("%d",&rooms);

    vector<stu> stu_arr;
    for(int i=0;i<rooms;i++){
        int room_persons=0;
        scanf("%d",&room_persons);
        vector<stu> stu_arr_one_room(room_persons);
        for(int j=0;j<room_persons;j++){
            scanf("%lld%d",&stu_arr_one_room[j].id,\
                &stu_arr_one_room[j].score);
            stu_arr_one_room[j].room = i+1;
        }

        sort(stu_arr_one_room.begin(),stu_arr_one_room.end(),cmp);
        if(room_persons!=0){
            stu_arr_one_room[0].room_rank = 1;
            for(int j=1;j<room_persons;j++){
                stu_arr_one_room[j].room_rank = 
                    (stu_arr_one_room[j-1].score == stu_arr_one_room[j].score)?
                    stu_arr_one_room[j-1].room_rank:j+1;

            }
        }
        

        stu_arr.insert(stu_arr.end(),stu_arr_one_room.begin(),stu_arr_one_room.end());
        sort(stu_arr.begin(),stu_arr.end(),cmp);
    }

    int rank = 1;
    printf("%d\n",stu_arr.size());
    for(vector<stu>::iterator iter = stu_arr.begin();\
        iter!=stu_arr.end();iter++){
        if(iter==stu_arr.begin()){
            iter->total_rank = 1;
        }else{
            iter->total_rank = ((iter-1)->score == iter->score)?\
                (iter-1)->total_rank:rank;
        }
        rank++;
        printf("%lld %d %d %d\n",iter->id,iter->total_rank,iter->room,iter->room_rank);
    }

    return 0;
    
}







