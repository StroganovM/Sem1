#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include<malloc.h>
#include <stdio.h>
#include <sstream>
#include<locale.h>
#include "StreamTable.cpp"
int main(){
	setlocale(LC_ALL, "Rus");
	StreamTable st(std::cout);
	st.SetCols(7, 25);
	st.MakeBorderExt(true);
	st.SetDelimRow(true, '-');
	st.SetDelimCol(true, '|');
	st << "����������" << "����� ������" << "������� �������" << "���-�� ������������" << "���������� ������������" <<  "���-�� ���������" << "������� ���������";
	st << "������" << "-" << "-" << "-" << "-" << "-" << "-";
	st << "���������� ���������" << "-" << "-" << "-" << "-" << "-" << "-";
	st << "���������� �������" << "-" << "-" << "-" << "-" << "-" << "-";
	st << "���������� �����" << "-" << "-" << "-" << "-" << "-" << "-";
	system("pause");
}
