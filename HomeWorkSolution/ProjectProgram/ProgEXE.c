#include<locale.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>
int rectangle() {
	int mcase1;
	float a, b, s, p, d;
	printf("Введите две стороны прямоугольника: ");
	scanf_s("%f %f", &a, &b);
loop1:
	system("cls");
	printf("Меню:\n");
	printf("1.Найти площадь прямоугольника.\n");
	printf("2.Найти периметр прямоугольника.\n");
	printf("3.Найти диагональ прямоугольника.\n");
	printf("4.Вернуться к выбору фигуры.\n");
	printf("0.Выйти.\n");
	printf("Ввод:");
	scanf_s("%d", &mcase1);
	if (mcase1 == 4) {
		system("cls");
		return menu();
	}
	else if (mcase1 == 0) {
		system("cls");
		return 0;
	}
	else if (mcase1 == 1) {
		s = a * b;
		printf("Площадь прямоугольника: %.2f\n", s);
	}
	else if (mcase1 == 2) {
		p = 2 * (a + b);
		printf("Периметр равен: %.2f\n", p);
	}
	else if (mcase1 == 3) {
		d = sqrt(a * a + b * b);
		printf("Диагональ прямоугольника равна: %.2f\n", d);
	}
	system("pause");
	if ((mcase1 != 0) && (mcase1 != 4)) goto loop1;

	return 0;
}
int triangle() {
	int mcase2;
	float a, b, s, p, gipotenuza;
	printf("Введите две сторны прямоугольного треугольника:");
	scanf_s("%f %f", &a, &b);
loop2:
	system("cls");
	printf("Меню:\n");
	printf("1.Найти площадь треугольника.\n");
	printf("2.Найти периметр треугольника.\n");
	printf("3.Найти гипотенузу треугольника.\n");
	printf("4.Вернуться к выбору фигуры.\n");
	printf("0.Выйти.\n");
	printf("Ввод:");
	scanf_s("%d", &mcase2);
	if (mcase2 == 4) {
		system("cls");
		return menu();
	}
	else if (mcase2 == 0) {
		system("cls");
		return 0;
	}
	else if (mcase2 == 1) {
		s = 0.5 * (a + b);
		printf("Площадь треугольника равна: %.2f\n", s);
	}
	else if (mcase2 == 2) {
		gipotenuza = sqrt(a * a + b * b);
		p = a + b + gipotenuza;
		printf("Периметр треугольника: %.2f\n", p);
	}
	else if (mcase2 == 3) {
		gipotenuza = sqrt(a * a + b * b);
		printf("Гипотенуза треугольника: %.2f\n", gipotenuza);
	}
	system("pause");
	if ((mcase2 != 0) && (mcase2 != 4)) goto loop2;
	return 0;
}
int circle() {
	int mcase3;
	float r, s, l, d,pi;
	pi = 3.14;
	printf("Введите радиус круга:");
	scanf_s("%f", &r);
loop3:
	system("cls");
	printf("Меню:\n");
	printf("1.Найти площадь круга.\n");
	printf("2.Найти длину окружности круга.\n");
	printf("3.Найти диаметр круга.\n");
	printf("4.Вернуться к выбору фигуры.\n");
	printf("0.Выйти\n");
	printf("Ввод:");
	scanf_s("%d", &mcase3);
	if (mcase3 == 4) {
		system("cls");
		return menu();
	}
	else if (mcase3 == 0) {
		system("cls");
		return 0;
	}
	else if (mcase3 == 1) {
		s = pi * r * r;
		printf("Площадь круга: %.2f\n", r);
	}
	else if (mcase3 == 2) {
		 l = 2 * pi*r;
		printf("Длина окружности: %.2f\n", l);
	}
	else if (mcase3 == 3) {
		d = 2 * r;
		printf("Диаметр окружности: %.2f\n", d);
	}
	system("pause");
	if ((mcase3 != 0) && (mcase3 != 4)) goto loop3;
	return 0;
	return 0;
}
int menu() {
	int select;
	printf("Выбор фигуры:\n");
	printf("1.Прямоугольник.\n");
	printf("2.Треугольник.\n");
	printf("3. Круг.\n");
	printf("0.Выйти из приложения\n");
	printf("Ввод:");
	scanf_s("%d", &select);
	system("cls");
	switch (select) {
	case 0:
		return 0;
		break;
	case 1:
		rectangle();
		break;
	case 2:
		triangle();
		break;
	case 3:
		circle();
		break;

	}
	return 0;
}
int main() {
	setlocale(LC_ALL, "RUS");
	printf("Добро пожаловать!\n");
	Sleep(1500);
	system("cls");
	printf("Загрузка.");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	system("cls");
	printf("Загрузка.");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(600);
	system("cls");
	menu();
	return 0;
}