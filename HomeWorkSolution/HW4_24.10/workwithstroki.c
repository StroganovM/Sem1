#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
char bigregisters(char*stroka) {
	int size = 0;
	while (stroka[size] != '\0') {
		size++;
	}
	for (int i = 0; i < size; i++) {
		stroka[i] = toupper(stroka[i]);
	}
	return(stroka);
}
char smallregisters(char* stroka) {
	int size = 0;
	while (stroka[size] != '\0') {
		size++;
	}
	for (int i = 0; i < size; i++) {
		stroka[i] = tolower(stroka[i]);
	}
	return(stroka);
}
char oppositeregisters(char*stroka) {
	int size = 0;
	while (stroka[size] != '\0') {
		size++;
	}
	for (int i = 0; i < size; i++) {
		if (isupper(stroka[i])) {
			stroka[i] = tolower(stroka[i]);
		}
		else {
			stroka[i] = toupper(stroka[i]);
		}
	}

	return(stroka);
}
char changestr(char*stroka) {
	printf("������� ����� ������: ");
	getchar();
	gets(stroka);
	printf("����� ������: ");
	return (stroka);
}
char cutstr(char*stroka) {
	int lastIndex = 0;
	printf("������� ����� ������: ");
	scanf_s("%d", &lastIndex);
	stroka[lastIndex] = '\0';
	printf("���������: ");
	puts(stroka);
	return(stroka);
}
char reversestr(char* stroka) {
	int c,i,j, size = 0;
	while (stroka[size] != '\0') {
		size++;
	}
	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		c = stroka[i];
		stroka[i] = stroka[j];
		stroka[j] = c;
	}
	return(stroka);
}

int main() {
	setlocale(LC_ALL, "RUS");
	char* stroka = (char*)malloc(sizeof(char) * 100);
	int select,select1, lastIndex,size=0,i=0,j=0,c=0;
	printf("������� ������: ");
	gets(stroka);
	while (1) {
		system("cls");
		printf("���� ������: ");
		puts(stroka);
		printf("1) �������� ������\n");
		printf("2) �������� ������\n");
		printf("3) ���������� ������\n");
		printf("4) ������� �������\n");
		printf("0) �����\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 0:
			return 0;
			break;
		case 1:
			changestr(stroka);
			puts(stroka);
			system("pause");
			break;

		case 2:
			cutstr(stroka);
			puts(stroka);
			system("pause");
			break;
		case 3:
			reversestr(stroka);
			puts(stroka);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("������� �������\n");
			printf("1)� ������� �������\n");
			printf("2)� ������ �������\n");
			printf("3)� ��������������� �������\n");
			scanf_s("%d", &select1);
			if (select1 == 1) {
				bigregisters(stroka);
				puts(stroka);
			}
			else if (select1 == 2) {
				smallregisters(stroka);
				puts(stroka);
			}
			else if (select1 == 3) {
				oppositeregisters(stroka);
				puts(stroka);
			}
			system("pause");
			break;
		}

	}

	return 0;
}