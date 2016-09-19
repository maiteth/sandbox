#include <stdio.h>

#include "./functions.h"
#define COUCOU
#ifdef COUCOU
#define HELLO 1
#else 
#define HELLO 2
#endif 

int main() { 
	int x = 4;
	int y = 3;
	int c;
	printf("c = %d\n", c);
	c = plus(x, y);
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("c = %d\n", c);
	
	printf("x - y = %d\n", moins(x, y));
	
	printf("x * y = %d\n", fois(x, y));
	
	printf("x / y = %d\n", div(x, y));
	
	printf("x %% y = %d\n", modulo(x, y));
	
	printf("x! = %d\n", factoriel2(x));
	
	printf("sqrt(3) = %f\n", racineCarree(3));
	
	printf("tangente(0.786) = %f\n", tangente(0.786));
	
	printf("HELLO= %d\n", HELLO);
	
	return 0;
}
