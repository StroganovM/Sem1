#include <locale.h>
#include<math.h>
#include<stdio.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int x1, x2, x3, y1, y2, y3, s, p, a, b, c;
	printf("������� ���������� � � � ������ �����: ");
	scanf_s("%d %d", &x1, &y1);
	system("cls");
	printf("������� ���������� � � � ������ �����: ");
	scanf_s("%d %d", &x2, &y2);
	system("cls");
	printf("������� ���������� � � � ������� �����:");
	scanf_s("%d %d", &x3, &y3);
	system("cls");
	a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	p = a + b + c;
	s = sqrt(p*0.5 * (p*0.5 - a) * (p*0.5 - b) * (p*0.5- c));
	printf("�������� ������������:%d.\n", p);
	printf("������� ������������:%d.\n", s);

	system("pause");
	return 0;
}