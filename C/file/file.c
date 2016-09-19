#include <stdio.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: file <f>\n\n");
		printf("Arguments: f is a file to examine.\n");
		return 1;
	}
	
	FILE *fp;
	fp = fopen(argv[1], "r");
	int c;
	while (1) {
		c = fgetc(fp);
		if (feof(fp)) { 
			break;
		}
		printf("%c", c);
	}
	fclose(fp);
	return 0;
}