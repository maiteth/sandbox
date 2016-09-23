#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void coucou() {
	char *buffer = (char *) malloc(3);
	strcpy(buffer, "ab");
	printf("buffer = %s\n", buffer);
	
	int *buffer2 = (int *) malloc(20000000 * sizeof(int));
	int x[2] = { 12, 14 };
	memcpy(buffer2, x, 2 * sizeof(int));
	printf("x = %d, %d\n", x[0], x[1]);
	printf("buffer2 = %d, %d\n", buffer2[0], buffer2[1]);
	printf("&buffer = %d\n", buffer);
	printf("&buffer2 = %d\n", buffer2);
	
	free(buffer);
	buffer = NULL;	
	
	free(buffer2);
	buffer2 = NULL;	
}

int main(int argc, char **argv) {
	while (1) {
		coucou();
	}
		
	return 0;
}
