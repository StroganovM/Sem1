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
	printf("Массив: ");
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
	printf("Минимум: %d\n", min);
}
void maxobjmass(int size, int max, int* mass) {
	max = mass[1];
	for (int i = 0; i < size; i++) {
		if (max < mass[i])
			max = mass[i];
	}
	printf("Максимум: %d\n", max);
}
void SredArifMmass(int size, int sum, int* mass) {
	for (int i = 0; i < size; i++) {
		sum += mass[i];
	}
	float sam = ((1.0*sum) / (1.0*size));
	printf("Сумма элементов массива: %d\n", sum);
	printf("Среднее арифметическое масива: %.2f", sam);
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "RUS");
	char str;
	int flag=0, select, size, min = 0, max = 0, sum = 0;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	size = abs(size);
	int* mass = (int*)malloc(sizeof(int) * size);
	while (1) {
		system("cls");
		printf("Меню: \n");
		if (flag==0){
			printf("Массив не сгенерирован!");
		}
		else {
			printf("Массив сгенерирован.");
		}
		printf("\n");
		printf("1)Сгенерировать случайный массив \n");
		printf("2)Найти минимум массива \n");
		printf("3)Найти максимум массива \n");
		printf("4)Найти среднее арифметическое массива \n");
		printf("5)Вывести массив на экран \n");
		printf("0)Выйти в окно \n");
		if (flag == 0) {
			printf("Автоматическая генерация массива\n");
			select = 1;
		}
		else {
			printf("Выбор: ");
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