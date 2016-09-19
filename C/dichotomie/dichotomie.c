#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int r = (rand() * 217333333) % 100;
	if (r < 0) {
		r = -r;
	}
	printf("r = %d\n", r);
	printf("RAND_MAX = %d\n", RAND_MAX);
	
	char answer[1000];
	while (1) {
		int a = 1;
		do {
			if (a == 0) {
				printf("Ne rentre pas n'importe quoi.\n");
			}
			printf("Devine le nombre (entre 0 et 100) : ");
			fgets(answer, 1000, stdin);
			a = atoi(answer);
		} while (a == 0 && answer[0] != '0');
		
		printf("Nombre rentre : %d\n", a);
		if (a > r) {
			printf("C'est moins.\n");
		} else if (a < r) {
			printf("C'est plus.\n");
		} else {
			printf("Bravo ! Le nombre recherche etait bien %d.\n", a);
			break;
		}
	}
	
	return 0;
}