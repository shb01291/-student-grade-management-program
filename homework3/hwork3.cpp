#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXCOUNT 100

typedef struct Student {
	char name[20];
	int korean;
	int english;
	int math;
	int sum;
	int avg;
	int rank;
}Student;



int sum(int a, int b, int c) {
	return a + b + c;
}

int avg(int a, int b, int c) {
	return (a + b + c) / 3;
}

int inputData(Student stu[100], int index) {
	printf("이름 국어 영어 수학순으로 가로로 입력하세요.\n");
	scanf("%s %d %d %d", stu[index].name, &stu[index].korean, &stu[index].english, &stu[index].math);
	stu[index].sum = sum(stu[index].korean, stu[index].english, stu[index].math);
	stu[index].avg = avg(stu[index].korean, stu[index].english, stu[index].math);

	return 0;
}



int rank(Student stu[100], int stuCnt) {
	int mSum = stu[stuCnt].sum;
	int mRank = 1;

	for (int i = 0; i < stuCnt; i++) {
		if (stu[i].sum > mSum)
			mRank++;
		else if (stu[i].sum == mSum)
			;
		else if (stu[i].sum < mSum)
			stu[i].rank++;
	}
	stu[stuCnt].rank = mRank;
	return mRank;
}

int printData(Student stu[100], int index) {
	printf("이름\t국어\t영어\t수학\t합계\t평균\t등수\n");
	printf("===================================================\n");
	for (int i = 0; i <= index; i++) {
		printf("%s\t %d\t %d\t %d\t %d\t %d\t %d\n\n", stu[i].name, stu[i].korean, stu[i].english, stu[i].math, stu[i].sum, stu[i].avg, stu[i].rank);
	}
	return 0;
}

int search(char* name, Student stu[100], int cnt) {

	for (int i = 0; i <= cnt; i++) {
		if (!strcmp(name, stu[i].name)) {
			printf("이름: %s\n", stu[i].name);
			printf("국어: %d점\n", stu[i].korean);
			printf("영어: %d점\n", stu[i].english);
			printf("수학: %d점\n", stu[i].math);
			printf("합계: %d점\n", stu[i].sum);
			printf("평균: %d점\n", stu[i].avg);
			printf("등수: %d등\n", stu[i].rank);
			return 1;
		}
	}
	printf("검색하고자 하는 사람이 없습니다.\n\n");
	return 0;
}


void main() {

	Student stu[100];
	char temp[20];
	int cnt = 0;
	int select = 0;

	inputData(stu, cnt);
	rank(stu, cnt);

	while (1) {
		printf("더 입력 하시겠습니까? 1.예 / 2.아니오: ");
		scanf("%d", &select);
		if (select == 1) {
			cnt++;
			inputData(stu, cnt);
			rank(stu, cnt);
		}
		else if (select == 2) {
			printData(stu, cnt);

			while (1) {
				printf("검색하고자 하는 사람의 이름:");
				scanf("%s", temp);

				if (search(temp, stu, cnt))
					break;
			}
		}
		else
		{
			printf("오류!! 제대로 입력하세요.\n");
		}

		if (select == 2) {
			break;
		}
	}
}

