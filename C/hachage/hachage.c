#include <stdio.h>

typedef struct _Element Element;
struct _Element {
	char key[32];
	int val;
	Element *next;
};

typedef struct _List List;
struct _List {
	Element *first;
};

typedef struct _Hash Hash;
struct _Hash {
	List buffer[500];
};

void hashInit(Hash *h) {
	
}

void hashSet(Hash *h, char *key, int val) {
	
}

int hashGet(Hash *h, char *key) {
	return 0;
}

void hashPrint(Hash *h) {
	
}

int main(int argc, char **argv) {
	Hash h;
	hashInit(&h);
	hashSet(&h, "Maite", 32);
	hashSet(&h, "JL", 17);
	hashPrint(&h);
	int v = hashGet(&h, "Maite");
	printf("v = %d\n", v);
	return 0;
}