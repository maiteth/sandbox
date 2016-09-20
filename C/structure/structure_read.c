#include <stdio.h>
#include <string.h>

#include "./types.h"

int main(int argc, char **argv) {
	
	Person famille[6];
	
	FILE *fp = fopen("famille.bin", "r");
	fread(famille, sizeof(Person), 6, fp);
	
	fclose(fp);
	
	for (int i = 0; i < 6; i++) {
		printPerson(&famille[i]);
	}
	
	return 0;
}