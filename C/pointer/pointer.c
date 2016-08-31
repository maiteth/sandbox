#include <stdio.h>



int main() {
	
	int i = 5;
	void *p = &i;
	printf("%d\n", p);
	printf("%d\n", i);
	printf("%d\n", *((int *) p));
	return 0;
}
