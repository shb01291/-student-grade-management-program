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
	printf("�̸� ���� ���� ���м����� ���η� �Է��ϼ���.\n");
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
	printf("�̸�\t����\t����\t����\t�հ�\t���\t���\n");
	printf("===================================================\n");
	for (int i = 0; i <= index; i++) {
		printf("%s\t %d\t %d\t %d\t %d\t %d\t %d\n\n", stu[i].name, stu[i].korean, stu[i].english, stu[i].math, stu[i].sum, stu[i].avg, stu[i].rank);
	}
	return 0;
}

int search(char* name, Student stu[100], int cnt) {

	for (int i = 0; i <= cnt; i++) {
		if (!strcmp(name, stu[i].name)) {
			printf("�̸�: %s\n", stu[i].name);
			printf("����: %d��\n", stu[i].korean);
			printf("����: %d��\n", stu[i].english);
			printf("����: %d��\n", stu[i].math);
			printf("�հ�: %d��\n", stu[i].sum);
			printf("���: %d��\n", stu[i].avg);
			printf("���: %d��\n", stu[i].rank);
			return 1;
		}
	}
	printf("�˻��ϰ��� �ϴ� ����� �����ϴ�.\n\n");
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
		printf("�� �Է� �Ͻðڽ��ϱ�? 1.�� / 2.�ƴϿ�: ");
		scanf("%d", &select);
		if (select == 1) {
			cnt++;
			inputData(stu, cnt);
			rank(stu, cnt);
		}
		else if (select == 2) {
			printData(stu, cnt);

			while (1) {
				printf("�˻��ϰ��� �ϴ� ����� �̸�:");
				scanf("%s", temp);

				if (search(temp, stu, cnt))
					break;
			}
		}
		else
		{
			printf("����!! ����� �Է��ϼ���.\n");
		}

		if (select == 2) {
			break;
		}
	}
}

