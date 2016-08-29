#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
extern char **environ;

int main(int argc, char **argv) {
	
	printf("PATH=%s\n", getenv("PATH"));
	printf("PATHEXT=%s\n", getenv("PATHEXT"));
	printf("USERDOMAIN=%s\n", getenv("USERDOMAIN"));
	
	int ret = putenv("BLABLA=coucou");
	if (ret != 0) {
		printf("error");
		return 1;
	}
	printf("BLABLA=%s\n", getenv("BLABLA"));
	ret = putenv("BLABLA=titi");
	if (ret != 0) {
		printf("error");
		return 1;
	}
	printf("BLABLA=%s\n", getenv("BLABLA"));
	
	ret = putenv("BLABLA=");
	if (ret != 0) {
		printf("error");
		return 1;
	}
	printf("BLABLA=%s\n", getenv("BLABLA"));
	for (char **env = environ; *env; ++env) {
		printf("%s\n", *env);
	}
        

	return 0;
}
