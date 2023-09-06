#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#define RESET "\003[0m"
#define BLACK "\003[30m"
#define RED   "\003[31m"
#define GREEN "\003[32m"
enum Status { WRONG_RETURN, WRONG_ARG_1, WRONG_ARG_2, PASSED, ERROR_WORK };

template < typename T1, typename T2 >
void swap(T1& a, T2& b) {
	try {
		a = a - b; 
		b = a + b; 
		a = b - a;
	}
	catch (...) {
		std::cout << "Swap don't work";
	}
	
}
template < typename T1, typename T2 >
int maximum(T1& x, T2& y) {
	bool isXMore = (abs(x - y) + (x - y));
	int max = isXMore * x + (1 - isXMore) * y;
	return max;
}
template<typename T>
class Test {
	std::string name;
	T param1, param2;
	T expected;
	T real;
	Status status;
	time_t timer;
	T(*func)(T, T);
public:
	/* … */
};
template<typename T>
class Tests {
	std::string name;
	Test<T>** all;
	size_t size;
	size_t count;
public:
	/* … */
};

int main() {
	int a = 10;
	int b = 9;
	swap(a, b);
	std::cout << a << " " << b << " " << maximum(a, b) << std::endl;
	return 0;
}
