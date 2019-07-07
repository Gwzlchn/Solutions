// 题目描述
// To evaluate the performance of our first year CS majored students, we consider 
// their grades of three courses only: C - C Programming Language, M - Mathematics 
// (Calculus or Linear Algebra), and E - English.  At the mean time, we encourage 
// students by emphasizing on their best ranks -- that is, among the four ranks with
//  respect to the three courses and the average grade, we print the best rank for each student.
// For example, The grades of C, M, E and A - Average of 4 students are given as the following:
// StudentID  C  M  E  A
// 310101     98 85 88 90
// 310102     70 95 88 84
// 310103     82 87 94 88
// 310104     91 91 91 91
// Then the best ranks for all the students are No.1 since the 1st one has done the best 
// in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, 
// and the last one in average.

// 输入描述:
// Each input file contains one test case.  Each case starts with a line containing 2 
// numbers N and M (<=2000), which are the total number of students, and the number of 
// students who would check their ranks, respectively.  Then N lines follow, each contains
//  a student ID which is a string of 6 digits, followed by the three integer grades (in
//  the range of [0, 100]) of that student in the order of C, M and E.  Then there are 
// M lines, each containing a student ID.


// 输出描述:
// For each of the M students, print in one line the best rank for him/her, and the
//  symbol of the corresponding rank, separated by a space.
// The priorities of the ranking methods are ordered as A > C > M > E.  Hence if there 
// are two or more ways for a student to obtain the same best rank, output the one 
// with the highest priority.
// If a student is not on the grading list, simply output "N/A".

// 输入例子:
// 5 6
// 310101 98 85 88
// 310102 70 95 88
// 310103 82 87 94
// 310104 91 91 91
// 310105 85 90 90
// 310101
// 310102
// 310103
// 310104
// 310105
// 999999

// 输出例子:
// 1 C
// 1 M
// 1 E
// 1 A
// 3 A
// N/A

#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>

#include<iostream>

using namespace std;

struct stu
{
	int id;
	int  score[4];
	int  rank[4];

	int best_rank = 5, best_sub = 0;
};

void set_rank(vector<stu>& stu_arr, int index) {

	if (stu_arr.size() == 0)
		return;

	stu_arr[0].rank[index] = 1;
	for (int i = 1; i < stu_arr.size(); i++) {
		if (stu_arr[i].rank[index] == stu_arr[i - 1].rank[index]) {
			stu_arr[i].rank[index] = stu_arr[i - 1].rank[index];
		}
		else {
			stu_arr[i].rank[index] = i + 1;
		}
	}
}

void set_best(vector<stu>& stu_arr) {
	for (auto iter = stu_arr.begin(); iter != stu_arr.end(); iter++) {
		int min_rank = iter->best_rank;

		for (int i = 0; i < 4; i++) {
			if (iter->rank[i] < min_rank) {
				min_rank = iter->best_rank = iter->rank[i];
				iter->best_sub = i;
			}
		}
		if (min_rank == iter->rank[3]) {
			iter->best_sub = 3;
		}
	}

}

int main() {
	int cnt, q_cnt;
	scanf("%d %d", &cnt, &q_cnt);

	vector<stu> stu_arr(cnt);
	for (int i = 0; i < cnt; i++) {

		scanf("%d %d %d %d",
			&stu_arr[i].id, &stu_arr[i].score[0], &stu_arr[i].score[1], &stu_arr[i].score[2]);
		stu_arr[i].score[3] = (stu_arr[i].score[0] + stu_arr[i].score[1] + stu_arr[i].score[2]) / 3;

	}

	for (int i = 0; i < 4; i++) {
		sort(stu_arr.begin(), stu_arr.end(), [i](stu s1, stu s2) {
			return  s1.score[i] > s2.score[i];
			});
		set_rank(stu_arr, i);
	}

	set_best(stu_arr);
	char rank_char[4] = { 'C','M','E','A' };

	for (int i = 0; i < q_cnt; i++) {
		int in_id = 0;
		scanf("%d", &in_id);

		auto res = find_if(stu_arr.begin(), stu_arr.end(), [&in_id](stu s1) {
			return s1.id == in_id;
			});
		if (res == stu_arr.end()) {
			printf("N/A");
		}
		else {
			printf("%d %c\n", res->best_rank, rank_char[res->best_sub]);
		}
	}

	return 0;

}


