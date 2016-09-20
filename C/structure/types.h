//Directive preprocesseur concernant l'alignement (sizeof = 45 et non 48)
#pragma pack(push, 1)

typedef struct _Person {
	char lastname[20];
	char firstname[20];
	int age;
	char gender;
} Person;

void printPerson(Person *p) {
	printf("Mon nom est %s, mon prenom est %s et j'ai %d ans.\n", p->lastname, p->firstname, p->age);
	if (p->gender == 'F') {
		printf("Je suis une fille.\n");
	} else if (p->gender == 'M') {
		printf("Je suis un garcon.\n");
	} else {
		printf("Je ne suis ni un garcon ni une fille.\n");
	}
}
