#include <stdio.h>

int main(int argc, char **argv) {
	for (int j = 0; j < 8; j++) {	
		for (int i = 0; i < 8; i++) {
			if ((i + j) % 2 == 0) {
				printf("\260\260");
			} else {
				printf("\262\262");
			}
		}
		printf("\n");
	}
	
	return 0;
}