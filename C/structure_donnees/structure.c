#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct _Element Element; //renommer un type (alias)
struct _Element { //on definit un nouveau type qui est une structure (en l'occurence recursif)
    int nombre; //premier membre (attribut) de la structure : valeur a indiquer dans la liste chainee
    Element *suivant; //second membre (attribut) de la structure : deinition du pointeur "suivant" qui pointe sur un element
};

typedef struct _Liste Liste;
struct _Liste {
    Element *first; //le pointeur s'appelle "first"
};

void printLinkedList(Liste *l) { 
	printf("Liste : ");
	Element *e = l->first; //l est un pointeur sur une structure ~ "first" est le nom du membre de la structure (ici de la Liste)
	while (e != NULL) { //tant que e n'est pas NULL (tant que la liste a des elements)
		printf("%d ", e->nombre); //e est un pointeur sur la structure Element et plus precisemment l'entier "e->nombre" designe le membre nombre
		e = e->suivant; //instruction d'incrementation (incrementation de l'adresse du pointeur)
	}
	printf("\n");
}

void add(Liste *l, int n) {
	Element *last = (Element *) malloc(sizeof(Element)); //on declare la variable "last" et l'on l'initialise sur on structure creee dans la heap avec malloc
	last->nombre = n;
	last->suivant = NULL;
	if (l->first == NULL) {
		l->first = last;
		return;
	}
	Element *e = l->first; //decalaration nouveau pointeur "e" qui vaut le contenu de "l->first"
	while (e->suivant != NULL) {
		e = e->suivant; //incrementation
	}
	e->suivant = last; //affectation de l'element a ajouter
}

int pop(Liste *l) { //pointeur sur la structure liste
	if (l->first == NULL) { //si la liste est vide
		errno = EPERM; //erreur
		return -1;
	}
	Element *last = l->first; //le pointeur "last" (NOUVEAU) vaut "l->first" (premier element de la liste chainee)
	Element *beforeLast = NULL; 
	while (last->suivant != NULL) {
		beforeLast = last; //iteration (=incrementation pour pointeurs)
		last = last->suivant;
	}
	int result = last->nombre; //last->nombre : recupere le nombre a renvoyer
	free(last);
	if (beforeLast) {
		beforeLast->suivant = 0;
	} else {
		l->first = NULL;
	}
	return result;
}

int shift(Liste *l) {
	if (l->first == NULL) {
		errno = EPERM;
		return -1;
	}
	Element *prems = l->first;
	Element *second = prems->suivant; 
	
	int result = prems->nombre;
	free(prems);
	if (second) {
		l->first = second;
	} else {
		l->first = NULL;
	}
	return result;
}

int main(int argc, char **argv) {
	Liste l = { first: NULL };
	printLinkedList(&l);
	add(&l, 10);
	add(&l, 5);
	add(&l, 8);
	add(&l, 2);
	printLinkedList(&l);
	
	int x = pop(&l);
	printLinkedList(&l);
	printf("x = %d\n", x);
	
	x = shift(&l);
	printLinkedList(&l);
	printf("x = %d\n", x);
	
	return 0;
}
