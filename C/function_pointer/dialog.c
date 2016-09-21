#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NORMAL 0
#define BONJOUR 1

void doNothing(const char *a, int *s) {
}

void doDefault(const char *a, int *s) {
	printf("tu as tape %s", a);
	*s = NORMAL;
}

void beep(const char *a, int *s) {
	printf("\7");
	*s = NORMAL;
}

void cafe(const char *a, int *s) {
	printf("Non desole, ca je ne sais pas faire.\n");
	*s = NORMAL;
}

void bonjour(const char *a, int *s) {
	printf("Bonjour, comment allez-vous ?\n");
	*s = BONJOUR;
}

void merci(const char *a, int *s) {
	printf("Super.\n");
	*s = NORMAL;
}

void plus(const char *a1, int *s) {
	printf("Je vais essayer de faire une addition\n");
	int a;
	int b;
	sscanf(a1, "+ %d %d\n", &a, &b);
	int c = a + b;
	printf("%d + %d = %d\n", a, b, c);
	*s = NORMAL;
}

void execute(const char *a, int *s) {
	
	// +8 = le pointeur va a l'adresse a + 8 (execute ) et n'affiche donc que la saisie
	const char *programme = a + 8;
	printf("Je vais essayer d'executer %s\n", programme);
	int status = system(programme);
	*s = NORMAL;
}

void choice(const char *a, int *s) {
	int choice;
	sscanf(a, "essai %d\n", &choice);
	switch (choice) {
		case 0:
			printf("cas 0\n");
			break;
		case 1:
			printf("cas 1\n");
			break;
		case 5:
			printf("cas cinq\n");
			break;
		default:
			printf("cas par defaut\n");
	}
	*s = NORMAL;
}

int main() {
	char answer[1000];
	int state = NORMAL;
	void (*instruction)(const char *, int *) = doNothing; //declaration du pointeur de fonction
	while (1) {
		printf("> ");
		fgets(answer, 1000, stdin);
				
		if (strcmp(answer, "quit\n") == 0) {
			break;
		} else if (strcmp(answer, "\n") == 0) {
			instruction = doNothing; //assignation d'une fonction au pointeur
		} else if (strcmp(answer, "repete\n") == 0) {
			//on laisse instruction comme il etait dans la boucle precedente
		} else if (strcmp(answer, "beep\n") == 0) {
			instruction = beep;
		} else if (strcmp(answer, "cafe\n") == 0) {
			instruction = cafe;
		} else if (strcmp(answer, "bonjour\n") == 0) {
			instruction = bonjour;
		} else if (state == 1 && strcmp(answer, "bien merci\n") == 0) {
			instruction = merci;
		} else if (strncmp(answer, "+", 1) == 0) {
			instruction = plus;
		} else if (strncmp(answer, "essai ", 6) == 0) {
			instruction = choice;
		} else if (strncmp(answer, "execute ", 8) == 0) {
			instruction = execute;
		} else {
			instruction = doDefault;
		}
			
		instruction(answer, &state); //execution de la fonction pointee
	}
	
	return 0;
}
