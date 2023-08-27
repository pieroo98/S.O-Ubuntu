#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char **argv){

	char str[100];
	int i;

	scanf("%s", str);
	for (i=0; i<strlen(str); i++)
		str[i] = toupper(str[i]);

	printf("%s", str);

	return 0;
}
