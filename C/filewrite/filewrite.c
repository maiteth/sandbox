#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char **argv) {
	int status;
	if (argc < 2) {
		printf("Usage: %s <f>\n\n", basename(argv[0]));
		printf("Arguments: f is a file to write.\n");
		return 1;
	}
	
	unlink(argv[1]); //effacer un fichier
	
	FILE *fp;
	fp = fopen(argv[1], "w+");
	
	if (fp == NULL) { 
		printf("Cannot open file %s: %s\n",  argv[1], strerror(errno));
		
		return 2;
	}
	
	fputs("1234567890abcde\n", fp);
	status = fseek(fp, 0, SEEK_SET); //0 = position dans le fichier ~ SEEK_SET = position du curseur (ici = debut du fichier)
	if (status != 0) { 
		printf("fseek error\n");
		return 3;
	}
	
	fputs("hello", fp);
		
	fclose(fp);
	return 0;
} 