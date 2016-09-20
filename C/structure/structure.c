#include <stdio.h>
#include <string.h>

#include "./types.h"

int main(int argc, char **argv) {
	
	Person p;
	strcpy(p.lastname, "Thomias");
	strcpy(p.firstname, "Maite");
	p.age = 23;
	p.gender = 'F';

	printPerson(&p);
	
	Person p2 = {
		lastname: "Thomias", 
		firstname: "Julia",
		age: 20,
		gender: 'F'
	};
	
	printPerson(&p2);
	
	printf("Size of Person = %d\n", sizeof(Person));
	
	Person famille[6] = {
		{
			lastname: "Thomias", 
			firstname: "Pierre",
			age: 49,
			gender: 'M'
		},
		{
			lastname: "Thomias", 
			firstname: "Lucinda",
			age: 48,
			gender: 'F'
		},
		{
			lastname: "Thomias", 
			firstname: "Yannis",
			age: 24,
			gender: 'M'
		},
		{
			lastname: "Thomias", 
			firstname: "Maite",
			age: 23,
			gender: 'F'
		},
		{
			lastname: "Thomias", 
			firstname: "Julia",
			age: 20,
			gender: 'F'
		},
		{
			lastname: "Thomias", 
			firstname: "Kenzo",
			age: 14,
			gender: 'M'
		},
	};
	
	for (int i = 0; i < 6; i++) {
		printPerson(&famille[i]);
	}
	printf("Size of Famille = %d\n", sizeof(famille));
	
	FILE *fp = fopen("famille.bin", "w");
	fwrite(famille, sizeof(Person), 6, fp);
	
	fclose(fp);
	
	return 0;
}