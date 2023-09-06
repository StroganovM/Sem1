#include <locale.h>
#include<math.h>
#include<stdio.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int a,b,plus,minus,ymnoj,ostatok,sak, sam;
	float delenie;
	printf("¬ведите целые числа a и b: ");
	scanf_s("%d %d", &a,&b);
	plus = a + b;
	minus = a - b;
	ymnoj = a * b;
	delenie =(float) a / b;
	sak = (pow(a, 2) + pow(b, 2))* 0.5;
	sam = (abs(a) + abs(b))* 0.5;
	ostatok = a%b;
	printf("%d %d %d %.2f %d %d %d\n", plus, minus, ymnoj, delenie, sak, sam, ostatok);




	system("pause");
	return 0;
}