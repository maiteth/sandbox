#include <stdio.h>



int main() {
	
	char i = 'a';
	void *p = &i;
	printf("%d\n", p);
	printf("%c\n", i);
	printf("%c\n", *((char *) p));
	return 0;
}
