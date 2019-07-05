// 题目描述
// Given a list of N student records with name, ID and grade.  
//You are supposed to sort the records with respect to the grade 
// in non-increasing order, and output those student records of which the grades are in a given interval.

// 输入描述:
// Each input file contains one test case.  Each case is given in the following format:
// N
// name[1] ID[1] grade[1]
// name[2] ID[2] grade[2]
// ... ...
// name[N] ID[N] grade[N]
// grade1 grade2
// where name[i] and ID[i] are strings of no more than 10 characters with no space,
//  grade[i] is an integer in [0, 100], grade1 and grade2 are the boundaries of the grade's interval. 
//  It is guaranteed that all the grades are distinct.


// 输出描述:
// For each test case you should output the student records of which the grades are 
// in the given interval [grade1, grade2] and are in non-increasing order.  
// Each student record occupies a line with the student's name and ID, separated by one space.  
 //If there is no student's grade in that interval, output "NONE" instead.

// 输入例子:
// 4
// Tom CS000001 59
// Joe Math990112 89
// Mike CS991301 100
// Mary EE990830 95
// 60 100

// 输出例子:
// Mike CS991301
// Mary EE990830
// Joe Math990112

// 思路：countif sort STL函数

#include<cstdio>
#include<cstring>
#include<vector>
#include <algorithm>
using namespace std;

struct stu{
    char name[15];
    char id[15];
    int grade;
};

int cmp_stu(stu s1,stu s2){
    return s1.grade > s2.grade;
}

int up,down;
int boundaries(stu s1){
    return s1.grade<=up && s1.grade>= down;
}


int main(){
    int cnt;
    scanf("%d",&cnt);

    vector<stu> stu_arr(cnt);
    for(int i=0;i<cnt;i++){
        scanf("%s%s%d",stu_arr[i].name, stu_arr[i].id, &stu_arr[i].grade);
    }

    

    sort(stu_arr.begin(),stu_arr.end(),cmp_stu);

    scanf("%d%d",&down,&up);
    int cnt_bound = count_if(stu_arr.begin(),stu_arr.end(),boundaries);
    
    //printf("%d",cnt_bound);
    if(cnt_bound==0){
        printf("NONE");
    }

    for(int i=0;i<cnt;i++){
        if(stu_arr[i].grade>up || stu_arr[i].grade <down){
            continue;
        }else{
            printf("%s %s\n",stu_arr[i].name,stu_arr[i].id);
        }
    }


    return 0;

}