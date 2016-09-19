#include <stdio.h>
#include <unistd.h>

#define true 1

int main() {
	//coucou maite
	unsigned char i = 0;
	while (true) {
		printf("%d = |%c|\n", (int) i, i);
		if (i == 255) {
			break;
		}
		i++;
	}
	printf("Salut G\x82rard\n");	
	return 0;
}  
