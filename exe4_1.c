#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char **argv){


	execlp("echo", "echo", argv[1],NULL);

	printf("ERROR\n");

	return 0;
}
