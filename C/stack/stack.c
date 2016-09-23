#include <stdio.h>

//la stack va exploser avec la fonction recursive
void hello(int a) {
	int b[1000] = { 5 };
	printf("Coucou Maite, a = %d, b= %d.\n", a, b[0]);
	if (a < 1000000) {
		hello(a + 1);
	}
}

int main(int argc, char **argv) {
	hello(0);
	
	return 0;
}
