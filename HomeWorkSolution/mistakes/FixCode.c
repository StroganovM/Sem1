#include <stdio.h>
#include <locale.h>//���������� � �������, ��� ��� ������� �� ������
int main() {
	setlocale(LC_ALL, "rus");//��� ������� ���� �������� ��� ���� �����
	int age;
	printf("������� �������\n");//��� ����� ����� ������ ��� ��� ����
	scanf_s("%d", &age);//scanf_s ��� ��������� �����, �� ����� � scanf �� �� ����, ��� & ���
	if (age < 14)
		printf("%d - �������\n", age);//� ����� ������ ������ ����� � �������, �� ����� ������, � ��� �� ������ ���
	else if (14 <= age && age< 25)// ������� � ������� ������������ ����� ����� &&
		printf("%d - ���������\n", age);//%d, � �� %f
	else if (25 <= age && age < 60)// ������ ;
		printf("%d - ��������\n", age);//%d, � �� %f
	else
		printf("%d - ��������\n", age);
	system("pause");//����� ����� ������ �������� 
	return 0;
}