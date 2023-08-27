#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int pidFiglio1;

void manager (int sig){
	if (sig ==SIGUSR2)
	{
		printf("\n\ninizio figlio 1.\n");
	}
	
}
 
int main(int argc, char **argv){

int pid, i;
char c;
FILE *fp1,*fp2;
(void) signal (SIGUSR2,manager);
(void) signal (SIGCHLD,manager);
fp1=fopen("son1.txt","r");
if (fp1==NULL)
{
	printf("errore apertura son1.txt\n");
	return -1;
}
fp2=fopen("son2.txt","r");
if (fp2==NULL)
{
	printf("errore apertura son2.txt\n");
	return -2;
}

if ((pid = fork())==0){
	printf("\npid figlio 1 : %d\n", getpid());
	pidFiglio1=getpid();
	pause();
	for(i=0;i<50 ;i++){
		c = fgetc(fp1);
		fprintf(stdout,"%c",c);}
	printf("\n");
	fclose(fp1);
	kill(getppid(),SIGCHLD);
	exit(0);
}

if (pid>0){
	if ((pid = fork())==0){
		printf("\npid figlio 2 : %d\n", getpid());
		for(i=0;i<50 ;i++){
			c = fgetc(fp2);
			fprintf(stdout,"%c",c);
		}
		printf("\n");
		fclose(fp2);
		sleep(5);
		kill(getppid(),SIGCHLD);
		kill(pidFiglio1,SIGUSR2);
		exit(0);
	}
		pause();
		pause();
}
return 0;
}
