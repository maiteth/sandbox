#include <stdio.h>


void toString(int x);

int main() {
	for (int i = -10; i < 10; i++) {
		toString(i);
	}
	
	unsigned int x = 2147483648;
	toString(x);
	int y = 2147483648;
	toString(y);

	return 0;
}

void toString(int x) {
	printf("%3d=", x);
	
	for (int i = 31; i >= 0; i--) {
		//printf("i = %d\n", i);
		int j = 1 << i;
		//printf("j = %d\n", j);
		
		int z = (j & x) / j;
		printf("%d", z);
		if (i % 4 == 0) {
			printf(" ");
		}
		
	}
	printf("\n");
	return;
}
