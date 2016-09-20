#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char **argv) { //argc est un entier qui represente la longueur du tableau des arguments ~ argv est un tableau de chaine de caracteres
	if (argc < 2) { //2 correspond a la longueur attendue du tableau argv ~ si on ne rentre que "fileread" alors le programme ne sait pas quel fichier ouvrir
		printf("Usage: %s <f>\n\n", basename(argv[0]));
		printf("Arguments: f is a file to read.\n"); //le messages d'erreur quand on ne rentre pas le nom du fichier a ouvrir
		return 1; //Comme il s'agit d'une erreur on retourne 1 (!=0)
	}
	
	FILE *fp; //on declare la variable ~ fp est un pointeur
	fp = fopen(argv[1], "r"); //fb pointe sur le debut du tableau fopen qui prend deux parametres : le deuxieme element du tableau argv (index 2) et "r" (=read ~ pour lire le fichier)
	if (fp == NULL) { 
		printf("Cannot open file %s: %s\n",  argv[1], strerror(errno));
		
		return 2;
	}
	int c; //on declare c qui est de type entier
	while (1) { // tant que ce qui suit est vrai il faut afficher c
		c = fgetc(fp); //fgetc est la fonction qui va lire le fichier caractere apres caractere
		if (feof(fp)) { //si on arrive a la fin du fichier alors on sort du while
			break;
		}
		printf("%c", c);
	}
	fclose(fp); //fonction pour fermer le fichier
	return 0;
} 