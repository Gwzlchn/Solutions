// 题目描述
// Excel can sort records according to any column.  Now you are supposed to imitate this function.

// 输入描述:
// Each input file contains one test case.  For each case, the first line contains two integers N (<=100000) and C,
//  where N is the number of records and C is the column that you are supposed to sort the records with.  Then N lines follow, each contains a record of a student.  A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).


// 输出描述:
// For each test case, output the sorting result in N lines.  That is, if C = 1 then the records must be sorted in 
//increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; 
//and if C = 3 then the records must be sorted in non-decreasing order according to grades.  
//If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

// 输入例子:
// 3 1
// 000007 James 85
// 000010 Amy 90
// 000001 Zoe 60

// 输出例子:
// 000001 Zoe 60
// 000007 James 85
// 000010 Amy 90

#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct stu
{
    int id;
    char name[10];
    int score;
};

int col;

int cmp(stu s1,stu s2){
    if(col==1){
        return s1.id < s2.id;
    }else if(col == 2){
        if(strcmp(s1.name,s2.name)==0){
            return s1.id < s2.id;
        }else{
            return strcmp(s1.name,s2.name)<=0;
        }
    }else if(col == 3){
        if(s1.score == s2.score){
            return s1.id < s2.id;
        }else{
            return s1.score < s2.score;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d%d", &n, &col);
    vector<stu> node(n);
    for(int i = 0; i < n; i++)
        scanf("%d %s %d", &node[i].id, node[i].name, &node[i].score);

    sort(node.begin(),node.end(), cmp);
    for(int i = 0; i < n; i++)
        printf("%06d %s %d\n", node[i].id, node[i].name, node[i].score);
    return 0;
}

