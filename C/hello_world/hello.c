#include <stdio.h>

int main(int argc, char **argv) {
	char *name = "Maite";
	if (argc > 1) {
		name = argv[1];
	}
	printf("Hello World!\n");
	printf("Salut %s!\n", name);

	return 0;
}
