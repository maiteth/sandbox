#include <stdio.h>

int main(int argc, char **argv) {
	for (int i = argc-1; i >= 0; i--) {
		printf("%s\n", argv[i]);
	}
	
	for (int i = 9 ; i >= 0; i--) {
		printf("%d\n", i);
	}
	
	for (int i = 0; i < 10; i = i + 2) {
		printf("%d\n", i);
	}
		
	return 0;
} 