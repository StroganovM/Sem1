#define _CRT_SECURE_NO_WARNINGS

// библиотеки
#include <ctime>
#include <math.h>
#include <locale.h>
#include <string.h>
#include<malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include<cstdio>
#include <iostream>
#include "sys/stat.h"
//типа вообщето таблица
#include"StreamTable.cpp"
// управляющие консолью библиотеки
#include <windows.h>
#include <conio.h>

#define MENU_SIZE_4 4
#define MENU_SIZE_3 3
#define MENU_SIZE_2 2
#define MENU_SIZE_1 2
// основные ключи, которые могут пригодиться
#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
//функшн это базис
void RandomMass(int max_value, int min_value, int len, int* mass) {

    for (int i = 0; i < len; i++) {
        mass[i] = min_value + rand() % (max_value - min_value + 1);
    }

    return;
}
void ManualMass(int len, int* mass) {
    printf("Введите элементыты массива: \n");
    for (int i = 0; i < len; i++) {
        scanf_s("%d", &mass[i]);
    }
    return;
}
void PrintMass(int* mass, int len) {

    for (int i = 0; i < len; i++) {
        printf("%d ", mass[i]);
    }
    printf("\n");
    return;
}
void NaiveSearch(int required_value, int* mass, int len) {
    system("cls");
    int index_of_required_value = -1;
    for (int i = 0; i < len; i++) {
        if (mass[i] == required_value) {
            int index_of_desired_value = i;
            printf("Индекс желаемого значения = %d\n", index_of_desired_value);
            system("pause");
            return;
        }
    }

    if (index_of_required_value == -1) {
        printf("Массив не содержит такого значения\n");
    }
    return;

}
void BinarySearch(int* mass, int len) {
    system("cls");
    for (int i = 0; i < len - 1; i++) {
        if (mass[i] > mass[i + 1]) {
            printf("Бинарный поиск не применим к неотсортированному массиву. Если хотите применить бинарный посик, пожалуйста, отсортируйте массив.\n");
            return;
        }
    }
    int index_of_desired_value = -1;
    printf("Введите значение, которое хотите найти в массиве: ");
    int desired_value;
    scanf_s("%d", &desired_value);
    int left_border = 0;
    int right_border = len - 1;
    int midle = 0;
    while (left_border < right_border) {
        midle = (left_border + right_border) / 2 + 1;
        if (mass[midle] < desired_value) {
            left_border = midle + 1;
        }
        else if (mass[midle] > desired_value) {
            right_border = midle - 1;
        }
        else if (mass[midle] == desired_value) {
            index_of_desired_value = midle;
            printf("Индекс желаемого значения = %d\n", index_of_desired_value);
            break;
        }

    }
    if (index_of_desired_value == -1) {
        printf("Массив не содержит желаемого значения\n");
    }

    return;
}
void BubbleSort(int* mass, int size, int *countbs, int* count_comp_bs) {
  //  *countbs = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            (*count_comp_bs)++;
            if (mass[j - 1] > mass[j]) {
                (*countbs)++;
                int temp = mass[j - 1];
                mass[j - 1] = mass[j];
                mass[j] = temp;
                
            }
        }
    }
 
}
void InsertionSort(int size, int *mass, int*countis, int* countis2)
{
    int newElement, position ;

    for (int i = 1; i < size; i++)
    {
        newElement = mass[i];
        position = i - 1;
        while (position >= 0 && mass[position] > newElement)
        {
            (*countis)++;//сравнение
            mass[position + 1] = mass[position];
            position = position - 1;
            (*countis2)++;
        }
        (*countis)++;
        mass[position + 1] = newElement;
        (*countis2)++;
    }
   
    
    
}
void SortChoise(int size, int* mass,int*countch, int* countch2) {
        for (int i = 0; i < size; i++)
        {
            int minPosition = i;
            for (int j = i + 1; j < size; j++) {
                if (mass[minPosition] > mass[j])
                    minPosition = j;
                (*countch2)++;
            }

           int tmp = mass[minPosition];
            mass[minPosition] = mass[i];
            mass[i] = tmp;
            (*countch)++;//перестановка
        }
}
void ShellSort(int size, int* mass, int*countsh, int* countsh2)
{
    int i, j, k, increment, temp;

    int val;
    val = (int)log((float)size + 1) / log((float)2);
    increment = pow((float)2, val) - 1;
    while (increment > 0)
    {
        
        for (i = 0; i < increment; i++)
        {
            for (j = 0; j < size; j += increment)
            {
                temp = mass[j];
                for (k = j - increment; k >= 0 && temp < mass[k]; k -= increment)
                {
                    mass[k + increment] = mass[k];
                    (*countsh2)++;//сравнения
                    (*countsh)++;//перестановки
                }
                mass[k + increment] = temp;
                (*countsh)++;//перестановки
            }
        }
        val--;
        if (increment != 1)
            increment = pow((float)2, val) - 1;
        else
            increment = 0;
    }
}
int table(float buble_time, float insertion_time, float choise_time,float shell_time, int countbs, int count_comp_bs, int countis, int countis2, int countch, int countch2,int countsh, int countsh2) {
    setlocale(LC_ALL, "Rus");
    StreamTable st(std::cout);
    st.SetCols(7, 25);
    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');
    st << "Сортировка" << "Время работы" << "Разница времени" << "Кол-во перестановок" << "Увеличение перестановок" << "Кол-во сравнений" << "Разница сравнений";
    st << "Пузырёк" << buble_time << buble_time - min(buble_time, insertion_time, choise_time, shell_time) << countbs << "-" << count_comp_bs << "-";
    st << "Сортировка вставками" << insertion_time << insertion_time - min(buble_time, insertion_time, choise_time, shell_time) << countis2 << "-" << countis << "-";
    st << "Сортировка выбором" << choise_time << choise_time - min(buble_time, insertion_time, choise_time, shell_time) << countch << "-" << countch2 << "-";
    st << "Сортировка Шелла" << shell_time << shell_time- min(buble_time, insertion_time, choise_time, shell_time) << countsh2 << "-" <<countsh << "-";
    system("pause");
    return 0;
}

int main() {
    system("title Application");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    system("cls");

    // объявление переменных
    short choose_pos;                    // переменная дл¤ хранения выбранного пункта меню
    int iKey;                          // переменная для фиксации нажатой клавиши
    int exit_flag, flag_settings, flag_algorithms, flag_experemental, size,size1, searchValue, min_value, max_value,countbs = 0, countis=0, count_comp_bs=0, countis2=0, countch=0, countch2 = 0,countsh=0, countsh2=0;
    int* mass = NULL;
    int* mass1 = NULL;
    int* mass2 = NULL;
    int* mass3 = NULL;
    int* mass4 = NULL;
    COORD cursorPos;                   // управление положением курсора, чтобы менять выводимый текст
    const char* HomeMenu[MENU_SIZE_4] = { "Алгоритмы", "Настройки","Режим эксперимента" ,"Выход" };
    const char* SettingsMenu[MENU_SIZE_4] = { "Задать массив", "Посмотреть массив","Изменить путь до файлов" ,"Назад" };
    const char* CreationsMassMenu[MENU_SIZE_3] = { "Ручной ввод", "Рандомное заполнение массива", "Прочитать из файла" };
    const char* AlgorithmsMenu[MENU_SIZE_3] = { "Поиск", "Сортировки", "Назад" };
    const char* SearchMenu[MENU_SIZE_2] = { "Обычный", "Бинарный" };
    const char* SortMenu[MENU_SIZE_4] = { "Пузырёк", "Сортировка вставками", "Сортировка выбором","Сортировка Шелла (последовательность Хаббарда)"};
    const char* ExperementalMenu[MENU_SIZE_3] = { "Сравнение сортировок","Эффиктивность","Назад" };

    exit_flag = 0;
    flag_algorithms = 0;
    flag_settings = 0;
    choose_pos = 0;

    char dir[100] = "D:\\Project\\Laba\\Laba\\";
    char filename[100] = "input.txt";
    char filepath[200];

    while (!exit_flag) {
        system("cls");
        iKey = 67;
        cursorPos ={0,0};
        SetConsoleCursorPosition(hStdOut, cursorPos);
        while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
            switch (iKey) {
            case KEY_ARROW_UP:
                choose_pos--;
                break;
            case KEY_ARROW_DOWN:
                choose_pos++;
                break;
            }

            system("cls");

            if (choose_pos < 0) { choose_pos = MENU_SIZE_4 - 1; }
            if (choose_pos > MENU_SIZE_4 - 1) { choose_pos = 0; }

            for (short i = 0; i < MENU_SIZE_4; i++) {
                cursorPos ={ 3, i};
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", HomeMenu[i]);
            }

            cursorPos ={ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");
            cursorPos ={MENU_SIZE_4 + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            

            iKey = _getch();
        }

        switch (choose_pos) {
        case 0:
            system("cls");
            //типа алгоритмес
            flag_algorithms = 0;
            while (!flag_algorithms) {
                system("cls");
                iKey = 67;
                cursorPos ={ 0, 0 };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                    switch (iKey) {
                    case KEY_ARROW_UP:
                        choose_pos--;
                        break;
                    case KEY_ARROW_DOWN:
                        choose_pos++;
                        break;
                    }
                    system("cls");
                    if (choose_pos < 0) { choose_pos = MENU_SIZE_3 - 1; }
                    if (choose_pos > MENU_SIZE_3 - 1) { choose_pos = 0; }
                    for (short i = 0; i < MENU_SIZE_3; i++) {
                        cursorPos ={ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", AlgorithmsMenu[i]);
                    }
                    cursorPos ={ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");
                    cursorPos ={MENU_SIZE_3 + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    
                    iKey = _getch();
                }
                switch (choose_pos) {
                case 0:
                    system("cls");
                    iKey = 67;
                    cursorPos ={ 0, 0 };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                        switch (iKey) {
                        case KEY_ARROW_UP:
                            choose_pos--;
                            break;
                        case KEY_ARROW_DOWN:
                            choose_pos++;
                            break;
                        }
                        system("cls");
                        if (choose_pos < 0) { choose_pos = MENU_SIZE_2 - 1; }
                        if (choose_pos > MENU_SIZE_2 - 1) { choose_pos = 0; }
                        for (short i = 0; i < MENU_SIZE_2; i++) {
                            cursorPos ={ 3, i };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("%s \n", SearchMenu[i]);
                        }
                        cursorPos ={ 0, choose_pos };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf(">>");
                        cursorPos ={ MENU_SIZE_4 + 3 + 1, choose_pos };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        
                        iKey = _getch();
                    }
                    switch (choose_pos) {
                    case 0:
                        system("cls");
                        if (mass == NULL) {
                            printf("Необходимо создать массив\n");
                            system("pause");
                        }
                        else {
                            printf("Введите значение, которое хотите найти в массиве: \n");
                            scanf_s("%d", &searchValue);
                            NaiveSearch(searchValue, mass, size);
                        }
                        break;
                    case 1:
                        system("cls");
                        if (mass == NULL) {
                            printf("Необходимо создать массив\n");
                            system("pause");
                        }
                        else {
                        BinarySearch(mass, size);
                        system("pause");
                        }
                        break;
                    }
                    break;
                case 1:
                    system("cls");
                    iKey = 67;
                    cursorPos ={ 0, 0 };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                        switch (iKey) {
                        case KEY_ARROW_UP:
                            choose_pos--;
                            break;
                        case KEY_ARROW_DOWN:
                            choose_pos++;
                            break;
                        }
                        system("cls");
                        if (choose_pos < 0) { choose_pos = MENU_SIZE_4 - 1; }
                        if (choose_pos > MENU_SIZE_4 - 1) { choose_pos = 0; }
                        for (short i = 0; i < MENU_SIZE_4; i++) {
                            cursorPos ={ 3, i };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("%s \n", SortMenu[i]);
                        }
                        cursorPos ={ 0, choose_pos };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf(">>");
                        cursorPos ={ MENU_SIZE_4 + 3 + 1, choose_pos };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        
                        iKey = _getch();
                    }
                    //////
                    switch (choose_pos) {
                    case 0:
                        system("cls");
                        if (mass == NULL) {
                            printf("Необходимо создать массив\n");
                            system("pause");
                        }
                        else {
                            BubbleSort(mass, size, &countbs, &count_comp_bs);
                            printf("Массив отсортирован\n");
                            system("pause");
                        }
                        break;
                    case 1:
                        system("cls");
                        if (mass == NULL) {
                            printf("Необходимо создать массив\n");
                            system("pause");
                        }
                        else {
                            InsertionSort(size, mass, &countis,&countis2);
                            printf("Массив отсортирован\n");
                            system("pause");
                        }
                        break;
                    case 2:
                        system("cls");
                        if (mass == NULL) {
                            printf("Необходимо создать массив\n");
                            system("pause");
                        }
                        else {
                            SortChoise(size, mass,&countch, &countch2);
                            printf("Массив отсортирован\n");
                            system("pause");
                        }
                        break;
                    case 3:
                        system("cls");
                        if (mass == NULL) {
                            printf("Необходимо создать массив\n");
                            system("pause");
                        }
                        else {
                            ShellSort(size, mass,&countsh, &countsh2);
                            printf("Массив отсортирован\n");
                            system("pause");
                        }
                        break;
                    }
                    break;
                
                case 2:
                    system("cls");
                    ++flag_algorithms;
                    break;
                }
            }
            break;
        case 1:
            system("cls");
            //типа сетингс
            flag_settings = 0;
            while (!flag_settings) {
                system("cls");
                iKey = 67;
                cursorPos ={ 0, 0 };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                    switch (iKey) {
                    case KEY_ARROW_UP:
                        choose_pos--;
                        break;
                    case KEY_ARROW_DOWN:
                        choose_pos++;
                        break;
                    }
                    system("cls");
                    if (choose_pos < 0) { choose_pos = MENU_SIZE_4 - 1; }
                    if (choose_pos > MENU_SIZE_4 - 1) { choose_pos = 0; }
                    for (short i = 0; i < MENU_SIZE_4; i++) {
                        cursorPos ={ 3, i };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf("%s \n", SettingsMenu[i]);
                    }
                    cursorPos ={ 0, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    printf(">>");
                    cursorPos ={ MENU_SIZE_4 + 3 + 1, choose_pos };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    
                    iKey = _getch();
                }
                switch (choose_pos) {
                case 0:
                    system("cls");
                    iKey = 67;
                    cursorPos ={ 0, 0 };
                    SetConsoleCursorPosition(hStdOut, cursorPos);
                    while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                        switch (iKey) {
                        case KEY_ARROW_UP:
                            choose_pos--;
                            break;
                        case KEY_ARROW_DOWN:
                            choose_pos++;
                            break;
                        }
                        system("cls");
                        if (choose_pos < 0) { choose_pos = MENU_SIZE_3 - 1; }
                        if (choose_pos > MENU_SIZE_3 - 1) { choose_pos = 0; }
                        for (short i = 0; i < MENU_SIZE_3; i++) {
                            cursorPos ={ 3, i };
                            SetConsoleCursorPosition(hStdOut, cursorPos);
                            printf("%s \n", CreationsMassMenu[i]);
                        }
                        cursorPos ={ 0, choose_pos };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        printf(">>");
                        cursorPos ={ MENU_SIZE_3 + 3 + 1, choose_pos };
                        SetConsoleCursorPosition(hStdOut, cursorPos);
                        
                        iKey = _getch();
                    }
                    switch (choose_pos) {
                    case 0:
                        system("cls");
                        printf("Введите количествово элементов массива: ");
                        scanf_s("%d", &size);
                        free(mass);
                        
                        mass = (int*)malloc(sizeof(int) * size);
                     
                        ManualMass(size, mass);
                        for (int i = 0; i < size; ++i) {
                        }
                        system("pause");
                        break;
                    case 1:
                        system("cls");
                        printf("Введите количествово элементов массива: ");
                        scanf_s("%d", &size);
                        free(mass);
                       
                        mass = (int*)malloc(sizeof(int) * size);
                        
                        printf("Введите диапазончисел для генерации (min, max): ");
                        scanf_s("%d %d", &min_value, &max_value);
                        system("cls");
                        RandomMass(max_value, min_value, size, mass);
                        break;
                    case 2:
                        system("cls");
                        strcpy_s(filepath, sizeof filepath, dir);
                        strncat_s(filepath, 100, filename, 100);
                        FILE* input_file = NULL;
                        errno_t error;
                        error = fopen_s(&input_file, filepath, "r+");
                        if (input_file == NULL) {
                            printf("Ошибка при считывании! Иди переделывай! %d\n", error);
                        }
                        else {


                            if (fscanf_s(input_file, "%d", &size) != 1) {
                                printf("Ошибочка\n");
                                return 0;
                            }
                            mass = (int*)malloc(sizeof(int) * size);
                            for (int i = 0; i < size; i++) {
                                if (fscanf_s(input_file, "%d", &mass[i]) != 1) {
                                    printf("Ошибочка\n");
                                    return 0;
                                }
                            }
                            fclose(input_file);
                            printf("Это успех, данные были украдены из файла \n");

                        }
                        system("pause");
                        break;
                    }
                    break;
                case 1:
                    system("cls");
                    PrintMass(mass, size);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("Введите новый путь до файла");
                    printf("(Например: D:\\Project\\Laba\\Laba\\): ");
                   std::cin>>(dir);
                    break;
                case 3:
                    system("cls");
                    ++flag_settings;
                    break;
                }
            }
            break;
            //типа эксперементируем 
         case 2:
             system("cls");
             iKey = 67;
             cursorPos ={ 0, 0 };
             SetConsoleCursorPosition(hStdOut, cursorPos);
             while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
                 switch (iKey) {
                 case KEY_ARROW_UP:
                     choose_pos--;
                     break;
                 case KEY_ARROW_DOWN:
                     choose_pos++;
                     break;
                 }
                 system("cls");
                 if (choose_pos < 0) { choose_pos = MENU_SIZE_3 - 1; }
                 if (choose_pos > MENU_SIZE_3 - 1) { choose_pos = 0; }
                 for (short i = 0; i < MENU_SIZE_3; i++) {
                     cursorPos = { 3, i };
                     SetConsoleCursorPosition(hStdOut, cursorPos);
                     printf("%s \n", ExperementalMenu[i]);
                 }
                 cursorPos = { 0, choose_pos };
                 SetConsoleCursorPosition(hStdOut, cursorPos);
                 printf(">>", iKey);
                 cursorPos = { MENU_SIZE_3 + 3 + 1, choose_pos };
                 SetConsoleCursorPosition(hStdOut, cursorPos);
                 iKey = _getch();
                 switch (choose_pos) {
                 case 0:
                     system("cls");

                     float buble_start_time = clock();
                     BubbleSort(mass, size, &countbs, &count_comp_bs);
                     float buble_time = (clock()- buble_start_time)/1000;

                     float insertion_start_time = clock();
                     InsertionSort(size, mass,&countis,&countis2);
                     float insertion_time = (clock() - insertion_start_time)/1000;

                     float choise_start_time = clock();
                     SortChoise(size, mass,&countch, &countch2);
                     float choise_time = (clock() - choise_start_time)/1000;

                     float shell_start_time = clock();
                     ShellSort(size, mass,&countsh, &countsh2);
                     float shell_time = (clock() - shell_start_time)/1000;

                     table(buble_time, insertion_time, choise_time, shell_time,countbs, count_comp_bs, countis,countis2, countch, countch2, countsh, countsh2);
                     break;
                 }
         
             }

             break;

        case 3:
            exit_flag = 1;
            break;
        }
    }

    //пакусечки
    system("cls");
    printf("Goodbay!\n");

    //шутдаун
    free(mass);
    system("pause");
    return 0;
}