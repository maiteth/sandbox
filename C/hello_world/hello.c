#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	for (int i = 0; i < argc; i = i + 2) {
		printf("arg %d = %s\n", i, argv[i]);
	}
	char *name = "Maite";
	if (argc > 1) {
		name = argv[1];
	}
	
	printf("Hello World!\n");
	printf("Salut %s!\n", name);
	sleep(2);
	return 0;
}
