#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 500
#define KEY_SIZE 32

typedef struct _Element Element;
struct _Element {
	char key[KEY_SIZE];
	int val;
	Element *next;
};

typedef struct _List List;
struct _List {
	Element *first;
};

typedef struct _Hash Hash;
struct _Hash {
	List buffer[HASH_SIZE];
};

void listAdd(List *l, char *key, int val) {
	Element *last = (Element *) malloc(sizeof(Element));
	strncpy(last->key, key, KEY_SIZE);
	last->val = val;
	last->next = NULL;
	if (l->first == NULL) {
		l->first = last;
		return;
	}
	Element *e = l->first;
	while (e->next != NULL) {
		e = e->next;
	}
	e->next = last;
}

void hashInit(Hash *h) {
	memset(h, 0, sizeof(Hash));
}

int f(char *key) {
	int result = 0;
	for (int i = 0; key[i] == 0; i++) {
		int c = (int) key[i];
		result = result + c;
	}
	return result;
}

void hashSet(Hash *h, char *key, int val) {
	int offset = f(key) % HASH_SIZE;
	listAdd(&(h->buffer[offset]), key, val);
}

int listGet(List *l, char *key) {
	if (l->first == NULL) {
		//TODO: gerer l'erreur
		return -1;
	}
	Element *e = l->first;
	while (e) {
		if (strcmp(key, e->key) == 0) {
			return e->val;
		}
		e = e->next;
	}
	//TODO: gerer l'erreur
	 return -1;
}

int hashGet(Hash *h, char *key) {
	int offset = f(key) % HASH_SIZE;
	return listGet(&(h->buffer[offset]), key);
}

void elementPrint(Element *e) {
	printf("%s -> %d\n", e->key, e->val);
}

void listPrint(List *l) {
	if (l->first == NULL) {
		return;
	}
	Element *e = l->first;
	while (e) {
		elementPrint(e);
		e = e->next;
	}
}

void hashPrint(Hash *h) {
	for (int i = 0; i < HASH_SIZE; i++) {
		listPrint(&(h->buffer[i]));
	}
}

int main(int argc, char **argv) {
	Hash h;
	hashInit(&h);
	hashSet(&h, "Maite", 32);
	hashSet(&h, "JL", 17);
	hashPrint(&h);
	int v = hashGet(&h, "Maite");
	printf("v = %d\n", v);
	v = hashGet(&h, "Yannis");
	printf("v = %d\n", v);
	return 0;
}