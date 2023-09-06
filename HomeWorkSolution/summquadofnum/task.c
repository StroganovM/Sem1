#include<stdio.h>
#include<locale.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int kolvo, num,sum;
	sum = 0;
	printf("Введите количество элементов: ");
	scanf_s("%d", &kolvo);
	printf("Введите элементы: ");
	while (kolvo > 0) {
		scanf_s("%d",&num);
		kolvo = kolvo - 1;
		sum = (num * num) + sum;
	}
	printf("%d", sum);

	return 0;
}