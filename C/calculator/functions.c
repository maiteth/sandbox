#include <stdio.h>
#include <math.h>

int moins(int a, int b) {
	return a - b;
}

int fois(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	return a / b;
}

int modulo(int a, int b) {
	int c = a / b;
	int d = a - (b * c);
	return d;
}

int factoriel(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factoriel(n - 1);
}

int factoriel2(int n) {
	int result = 1;
	printf("au debut, result = %d\n", result);
	for (int i = 1; i <= n; i++) {
		printf("on multiplie result par i = %d\n", i);
		
		result = result * i;
		printf("result = %d\n", result);
	}
	printf("c'est la fin : result = %d\n", result);
	return result;
}

float racineCarree(float f) {
	return (float) sqrt((double) f);
}


float tangente(float f) {
	return (float) (sin((double) f) / cos((double) f));
}
