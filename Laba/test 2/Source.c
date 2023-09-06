#include "stdafx.h"
#include "stdio.h"
#include"Windows.h"
#include "locale.h"
typedef struct
    {
        int year;
        int ussr;
        int usa;
        int eng;
        int fran;
    }row;
int main() {

    
    row table[5];


#pragma warning (disable : 4996)
    
    int _tmain(int argc, _TCHAR * argv[])

    {
        setlocale(LC_ALL, "");

        char* nazva[] = { " Годы ",  " СССР ", " США ", " Англия ", " Франция " };
        printf("Введите данные: ");
        for (int i = 0; i < 4; i++)
        {
            printf("[%d]", i);
            scanf("%d", &table[i].year);
            scanf("%d", &table[i].ussr);
            scanf("%d", &table[i].usa);
            scanf("%d", &table[i].eng);
            scanf("%d", &table[i].fran);
        }
        for (int i = 0; i < 3; i++)
        {
            printf("%s ", nazva[i]);
            printf("%d ", table[i].year);
            printf("%d ", table[i].ussr);
            printf("%d ", table[i].usa);
            printf("%d ", table[i].eng);
            printf("%d ", table[i].fran);
            printf("\n");
        }
        system("pause");
        return 0;
    }
       