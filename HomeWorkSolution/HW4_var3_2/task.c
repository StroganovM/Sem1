#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char strplusstr(int size1,int size2,char*mass1, char* mass2, char* mass3) {
	while (mass1[size1] != '\0') {
		size1++;
	}
	while (mass2[size2] != '\0') {
		size2++;
	}
	
	for (int i=0; i < size1; i++) {
		mass3[i]= mass1[i];	
	}
	for (int i = 0; i < size2; i++) {
		mass3[size1+i] = mass2[i];
	}
	return(mass3);
}
int main(){
	char* mass1 = (char*)malloc(sizeof(char) * 100);
	char* mass2 = (char*)malloc(sizeof(char) * 100);
	int size1 = 0, size2 = 0;
	char* mass3 = (char*)malloc(sizeof(char) * (size1 + size2));
	
	printf("Enter first str: ");
	gets(mass1);
	printf("Enter second str: ");
	gets(mass2);
	strplusstr(size1,size2,mass1, mass2,mass3);
	printf("Result str: ");
	puts(mass3);
	return 0;
}