#include <stdio.h>
#include <malloc.h>
#include <math.h>
int main() {
	int  n, m=n,sum=0, size=n;
	int* matr[m][n];
	for (int n = 0; n < size; n++, n++) {
		sum += matr[m][n];
		size--;
	}
	printf("%d", sum);
    
	return 0;
}
