#include <stdio.h>
#include <stdlib.h>

int main() {
	char a[20];
	char b[20] = "hello";
	char b1[20] = {'h', 'e', 'l', 'l', 'o', '\0'};
	printf("b = |%s|\n", b);
	printf("b1 = |%s|\n", b1);
	int c[20];
	int d[4] = {13, 20, 22, 54};
	char answer[1000];
	printf("Entre une longueur : ");
	fgets(answer, 1000, stdin);
	int length = atoi(answer);
	for (int i = 0; i < length; i++) {
		printf("d[%d] = |%d|\n", i, d[i]);
	}
	
	int matrice[2][4][3] = {{{6, 17, 15}, {24, 63, 8}, {80, 19, 1}, {13, 72, 63}}, {{6, 17, 15}, {24, 63, 8}, {80, 19, 1}, {13, 72, 63}}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				printf("|%d| ", matrice[i][j][k]);
			}
			printf("\n");
		}
		printf("---------------------------------------------\n");
	}
	
	char tableau[3][20] = {"Hello", "Maite", "Ca va ?"};
	printf("tableau[0] = |%s|\n", tableau[0]);
	printf("tableau[1] = |%s|\n", tableau[1]);
	printf("tableau[2] = |%s|\n", tableau[2]);
	
	{
		int a;
		int b;
		int f;
		
		for (int i = 0; i < 3; i++) {
			printf("i = %d\n", i);
			printf("coucou\n");
		}
		
	}
	
	return 0;
}