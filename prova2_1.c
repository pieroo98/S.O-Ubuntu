#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#define M 500

int main(int argc, char **argv){
	pid_t pid;
	pid = atoi(argv[1]);
	if (strcmp(argv[2],"somma")==0){
		kill(pid,12);
	}
	else if (strcmp(argv[2],"differenza")==0){
		kill(pid,10);
	}
	else if (strcmp(argv[2],"fine")==0){
		kill(pid,2);
		exit(3);
	}
	return 0;
}
