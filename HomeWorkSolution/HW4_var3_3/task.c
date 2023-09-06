#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void PrintMass(int size, int* mass) {
	
}
int main() {
	setlocale(LC_ALL, "RUS");
	int size,index, j, k, tmp = 0;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	size = abs(size);
	int* mass = (int*)malloc(sizeof(int) * size);
	printf("Введите массив: ");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &mass[i]);
	}
	
	for (int i = 0; i < size -1 ; i++) {
		for (int j = i+1; j < size; j++)
		{
			if ((mass[i] > mass[j]) && (mass[i] % 2 == 0 && mass[j] % 2 == 0)){
				tmp = mass[i];
				mass[i] = mass[j];
				mass[j] = tmp;
			}
	
		}
	}
	printf("Массив:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", mass[i]);
	}
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		if (mass[i] % 2 == 0)
		{
			printf("%d ", mass[i]);
		}
		else
		{
			if (mass[i] < 10)
			{
				printf("  ");
			}
			else if (mass[i] < 100 && mass[i] >= 10)
			{
				printf("   ");
			}
			else if (mass[i] < 1000 && mass[i] >= 100)
			{
				printf("    ");
			}
		}
	}
	return 0;
}
	