#include <stdio.h>

#define FLOAT 0
#define INT 1


void toString(void *x, int type);

int main() {
	printf("Starting\n");
	for (float i = 0.5; i < 10.0; i++) {
		toString(&i, FLOAT);	
	}
	float n = 0.1;
	toString(&n, FLOAT);
	
	for (int i = 0; i < 10; i++) {
		toString(&i, INT);	
	}
	
	return 0;
}

void toString(void *x, int type) {
	if (type == FLOAT) {
		printf("%20.10f=", *((float *) x));	
	} else {
		printf("%20d=", *((int *) x));
	}
	
	int n = *((int *) x);
	for (int i = 31; i >= 0; i--) {
		//printf("i = %d\n", i);
		int j = 1 << i;
		//printf("j = %d\n", j);
		
		int z = (j & n) / j;
		printf("%d", z);
		if (type == FLOAT) {
			if ((i == 31) || (i == 27) || (i == 23)  || (i == 19) || (i == 15) || (i == 11) || (i == 7)) {
				printf(" ");
			}
		} else {
			if (i % 4 == 0) {
				printf(" ");
			}
		}
	}
	
	printf("\n");
	return;
}
