#include <locale.h>
#include<math.h>
#include<stdio.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int a, sb, sp, v;
	printf("������� ������ ����� ����: ");
	scanf_s("%d", &a);
	v = pow(a, 3);
	sp = 6 * pow(a, 2);
	sb = 4 * pow(a, 2);
	printf("����� = %d\n",v);
	printf("������� ������� ����������� = %d\n",sb);
	printf("������� ������ ����������� = %d\n",sp);
	system("pause");
	return 0;
}