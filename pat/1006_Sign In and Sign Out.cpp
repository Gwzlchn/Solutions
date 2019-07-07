// At the beginning of every day, the first person who signs in the computer room will unlock the door, and
// the last one who signs out will lock the door. Given the records of signing in’s and out’s, you are
// supposed to find the ones who have unlocked and locked the door on that day.


// Input Specification:
// Each input file contains one test case. Each case contains the records for one day. The case starts with a
// positive integer M, which is the total number of records, followed by M lines, each in the format:
// ID_number Sign_in_time Sign_out_time
// where times are given in the format HH:MM:SS, and ID number is a string with no more than 15
// characters.

// Output Specification:
// For each test case, output in one line the ID numbers of the persons who have unlocked and locked the
// door on that day. The two ID numbers must be separated by one space.
// Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the
// sign out time for each person, and there are no two persons sign in or out at the same moment.

// Sample Input:
// 3
// CS301111 15:30:28 17:00:10
// SC3021234 08:00:00 11:25:25
// CS301133 21:45:00 21:58:40

// Sample Output:
// SC3021234 CS301133

#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct stu{
    string id;
    long sign_in;
    long sign_out;
};

int cmp_in(stu s1,stu s2){
    return s1.sign_in < s2.sign_in;
}

int cmp_out(stu s1,stu s2){
    return s1.sign_out < s2.sign_out;
}

int main(){
    int cnt;
    cin>>cnt;
    vector<stu> stu_vec(cnt);


    for(int i=0;i<cnt;i++){
        cin>>stu_vec[i].id;
        int in_h,in_m,in_s,out_h,out_m,out_s;
        scanf("%d:%d:%d %d:%d:%d",&in_h,&in_m,&in_s,&out_h,&out_m,&out_s);

        stu_vec[i].sign_in = in_h * 3600 + in_m * 60 + in_s;
        stu_vec[i].sign_out = out_h * 3600 + out_m * 60 + out_s;
    }

    sort(stu_vec.begin(),stu_vec.end(),cmp_in);
    cout<<stu_vec[0].id<<" ";

    sort(stu_vec.begin(),stu_vec.end(),cmp_out);
    cout<<stu_vec.rbegin()->id;
}

