#include<stdio.h>
#include<math.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	int x, y, z;
	printf("Ввидите переменные X, Y, Z\n");
	scanf_s("%d %d %d", &x, &y, &z);
	if (x != y && x != z && y != z) {
		if (x > y && x > z) {
			z += x;
		}
		else if (y > x && y > z) {
			z += y;
		}

		else {
			z *= z;
			printf("%d\n", z);
		}
	
	}
    else if (x == y && x == z) {
		printf("Все переменные равны!\n");
	}
	else if (x == y) {
		printf("X=Y\n");
	}
	else if (x == z) {
		printf("X=Z\n");
	}
	else if (y == z) {
		printf("Y=Z\n");
	}

	
	system("pause");
	return 0;
}