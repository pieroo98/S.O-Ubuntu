#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	printf("A\n");
	int pid=fork();
	printf("B\n");
	if (pid){
		printf("pid del padre\n");
		wait(NULL);
	}
	else
	{
		printf("C\n");
		exit(0);
	}
}
