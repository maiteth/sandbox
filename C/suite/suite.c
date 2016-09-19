#include <stdio.h>

int main() {
	printf("Bonjour\n");
	
	float u = 0;
	int p = 1;
	for (int i = 0; i < 50; i++) {
		p *= 2;
		u = u + (1.0 / p);
		printf("u(%d) = %.10f\n", i, u);

	}
	
	return 0;
}