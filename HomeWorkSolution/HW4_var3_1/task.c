#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void generate_mass(int size, int*mass) {
	for (int i = 0; i < size; i++) {
		mass[i] = rand();
	}
}
void PrintMass(int size, int* mass){
	printf("������: ");
	for (int i = 0; i < size; i++) {
		
		printf("%d ", mass[i]);
	}
}
void minobjmass(int size, int min,int*mass) {
	min = mass[1];
	for (int i = 0; i < size; i++) {
		if (min > mass[i])
			min = mass[i];
	}
	printf("�������: %d\n", min);
}
void maxobjmass(int size, int max, int* mass) {
	max = mass[1];
	for (int i = 0; i < size; i++) {
		if (max < mass[i])
			max = mass[i];
	}
	printf("��������: %d\n", max);
}
void SredArifMmass(int size, int sum, int* mass) {
	for (int i = 0; i < size; i++) {
		sum += mass[i];
	}
	float sam = ((1.0*sum) / (1.0*size));
	printf("����� ��������� �������: %d\n", sum);
	printf("������� �������������� ������: %.2f", sam);
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "RUS");
	char str;
	int flag=0, select, size, min = 0, max = 0, sum = 0;
	printf("������� ������ �������: ");
	scanf_s("%d", &size);
	size = abs(size);
	int* mass = (int*)malloc(sizeof(int) * size);
	while (1) {
		system("cls");
		printf("����: \n");
		if (flag==0){
			printf("������ �� ������������!");
		}
		else {
			printf("������ ������������.");
		}
		printf("\n");
		printf("1)������������� ��������� ������ \n");
		printf("2)����� ������� ������� \n");
		printf("3)����� �������� ������� \n");
		printf("4)����� ������� �������������� ������� \n");
		printf("5)������� ������ �� ����� \n");
		printf("0)����� � ���� \n");
		if (flag == 0) {
			printf("�������������� ��������� �������\n");
			select = 1;
		}
		else {
			printf("�����: ");
			scanf_s("%d", &select);
		}
		
		switch (select) {
		case 0:
			return 0;
			break;
		case 1:
			generate_mass(size, mass);
			flag = 1;
			system("pause");
			break;
		case 2:
			PrintMass(size, mass);
			printf("\n");
			minobjmass(size, min, mass);
			system("pause");
			break;
		case 3:
			PrintMass(size, mass);
			printf("\n");
			maxobjmass(size, max, mass);
			system("pause");
			break;
		case 4:
			PrintMass(size, mass);
			printf("\n");
			SredArifMmass(size, sum, mass);
			system("pause");
			break;
		case 5:
			PrintMass(size, mass);
			printf("\n");
			system("pause");
			break;
		}
	}
	free(mass);
	return 0;
}