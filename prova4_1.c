#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#define M 110

int main(){
	char stringa[M]={};
	printf("inserisci una stringa : \n");
	fgets(stringa,M,stdin);
	execlp("echo","echo",stringa,NULL);
	return 0;
}
