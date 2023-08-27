#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#define max 200

void manager(int sig){
	if (sig == SIGUSR1){
		exit(1);}
}

int main(int argc, char **argv){

signal(SIGUSR1,manager);

int fp[2], pid, n=0;
char buf[max]={0}, stampa[max]={0};
FILE *file;
if (pipe(fp)==0){
	pid = fork();
	if (pid<0)
		printf("errore fork");

	else if (pid==0){
		file = fopen("son1.txt","r");
		if (file==NULL){
			printf("errore apertura file.\n");
			exit(0);}
		close(fp[0]);
		while(fgets(buf,max,file)!=NULL){
			n=write(fp[1],buf,max);
			printf("LETTI: %d\n",n);
			sleep(1);
		}
		kill(getppid(),SIGUSR1);
		fclose(file);
		exit(0);
	}
	else if (pid>0){
		close(fp[1]);
		while(1){
			n = read(fp[0],stampa,max);
			fprintf(stdout,"SCRITTI: %s %d\n",stampa,n);
		}
	}
}
return 0;
}
