#include<stdio.h>
#include<math.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	int exam1, exam2, exam3;
	printf("������� ���� ������:\n");
	scanf_s("%d %d %d", &exam1, &exam2, &exam3);
	if (exam1 < 3 || exam2 < 3 || exam3 < 3) {
		printf("�� ��������!\n");
	}
	
	else if (exam1==5 && exam2==5 && exam3==5) {
		printf("�� ��������!\n");
	}
	else if (exam1 == 3 || exam2 == 3 || exam3 == 3) {
		printf("�� ��������!\n");
	}
	else {
		printf("�� ��������!\n");
	}
	system("pause");
	return 0;
}