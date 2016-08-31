#include <stdio.h>
#include <unistd.h>

#define true 1

int main() {
	unsigned char i = 0;
	while (true) {
		printf("%d = |%c|\n", (int) i, i);
		if (i == 255) {
			break;
		}
		i++;
	}
		
	return 0;
}  
