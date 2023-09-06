#pragma warning(disable : 4996)
#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main() {
	char* word1 = (char*)malloc(sizeof(char) * 100);
	char* word2 = (char*)malloc(sizeof(char) * 100);
	printf("Enter first text: ");
	gets(word1);
	printf("Enter second text: ");
	gets(word2);
    strcat(word1," ");
    strcat(word1, word2);
	 
	printf("Result: ");
	puts(word1);
	free(word1);
	free(word2);
	return 0;
	
}