#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int a, b, nod, select1, select;
	printf("Меню\n");
	printf("1.1)Задача 1\n");
	printf("1.2)Задача 2\n");
	printf("1.0)Выход\n");
	printf("Ваш выбор: ");
	scanf_s("%d.%d", &select1, &select);
	switch (select) {
	case 1:
		printf("Задача 1\n");
		printf("Введите a и b: ");
		scanf_s("%d %d", &a, &b);
		for (int i = 1; i <= a; i++) {
			if (a % i == 0 && b%i==0) {
				nod = i;
			}
		}
		printf("%d",nod);
		break;
	case 2:
		printf("Задача 2\n");
		break;
	case 0: {
		return 0;
		break;
	}
	}

	return 0;
}